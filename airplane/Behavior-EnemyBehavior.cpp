#include <cmath>
#include <random>
#include <unordered_map>
#include "Behavior-EnemyBehavior.h"
#include "system-engine.h"
#include "system-system.h"
#include"core-Player.h"
static std::random_device rd;
static std::mt19937 gen(rd());
const int ScreenX = AllGame::instance().ScreenX;
const int ScreenY = AllGame::instance().ScreenY;
// 每个敌机独立的风筝方向
static std::unordered_map<Enemy*, int> fengzhengDir;

// 每个敌机 JinJun 的随机 vx 平滑系统
static std::unordered_map<Enemy*, float> jinCurrentVx;
static std::unordered_map<Enemy*, float> jinTargetVx;

// 生成 1/4 区域内的随机坐标
std::pair<int, int> RandomLocationProduce(Enemy* e) {
    static std::random_device rd;
    static std::mt19937 gen(rd());

    // 根据 type 匹配 rad（碰撞圆半径）
    switch (e->type) {
    case 0: e->rad = 45 / 2; break;
    case 1: e->rad = 60 / 2; break;
    case 2: e->rad = 70 / 2; break;
    }

    // X 轴随机范围 [e->rad, ScreenX - e->rad]
    std::uniform_int_distribution<int> disX(e->rad, ScreenX - e->rad);
    e->coord.first = disX(gen);

    // Y 轴随机范围 [e->rad, ScreenY/4 - e->rad]（上方 1/4 区域）
    int topQuarterHeight = ScreenY / 4;
    std::uniform_int_distribution<int> disY(e->rad, topQuarterHeight - e->rad);
    e->coord.second = disY(gen);

    return e->coord;
}

// 计算系数
int CalculateCoef(Enemy* e) {
    return e->type + 1;
}

// 随机生成 modol (0: 小型 1: 中型 2: 大型)
int RandomModol(Enemy* e) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, 2);

    e->modol = dis(gen);
    return e->modol;
}

// 随机类型（随时间调整权重）
int RandomType(Enemy* e) {
    int gameTime = AllGame::instance().GameTime;
    int minute = gameTime / 60;

    std::vector<int> weights;

    if (minute < 1) {
        weights = { 70, 25, 5 };
    }
    else if (minute < 3) {
        weights = { 20, 30, 40 };
    }
    else if (minute < 5) {
        weights = { 0, 40, 40 };
    }
    else {
        weights = { 0, 10, 90 };
    }

    int total = weights[0] + weights[1] + weights[2];
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, total);
    int r = dis(gen);

    if (r <= weights[0]) {
        e->type = 0;
        return 0;
    }
    else if (r <= weights[0] + weights[1]) {
        e->type = 1;
        return 1;
    }
    else {
        e->type = 2;
        return 2;
    }
}

// 根据 Type 匹配半径
int RadMatchType(Enemy* e) {
    switch (e->type) {
    case 0: e->rad = 22; return 22;
    case 1: e->rad = 30; return 30;
    case 2: e->rad = 35; return 35;
    }
    return 0;
}

// 根据 Type 匹配最大 HP
int MaxHpMatchType(Enemy* e) {
    switch (e->type) {
    case 0: e->maxHp = 20; return 20;
    case 1: e->maxHp = 45; return 45;
    case 2: e->maxHp = 135; return 135;
    }
    return 0;
}

// ==========================================================
// 0：风筝（独立 dir）
// ==========================================================
std::pair<int, int> Behavior_FengZheng(Enemy* e) {

    if (!fengzhengDir.count(e)) {
        fengzhengDir[e] = 1;  // 初始向右
    }

    int& dir = fengzhengDir[e];

    if (e->coord.first - e->rad <= 0) dir = 1;
    else if (e->coord.first + e->rad >= ScreenX) dir = -1;

    int vx = dir * (sqrt(e->vx * e->vx + e->vy * e->vy)) * CalculateCoef(e);
    int vy = 0;

    return { vx, vy };
}



// ==========================================================
// 1：歼灭（追踪玩家）
// ==========================================================
std::pair<int, int> Behavior_JianMie(Enemy* e, Player* p) {

    double dx = p->coord.first - e->coord.first;
    double dy = p->coord.second - e->coord.second;

    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist < 1.0) dist = 1.0;  // 避免除 0

    double ux = dx / dist;
    double uy = dy / dist;

    int speedBase = (sqrt(e->vx * e->vx + e->vy * e->vy)) * CalculateCoef(e);

    int vx = static_cast<int>(ux * speedBase);
    int vy = static_cast<int>(uy * speedBase);

    if (vx == 0 && dx > 0) vx = 1;
    if (vx == 0 && dx < 0) vx = -1;

    return { vx, vy };
}



// ==========================================================
// 2：进军（vx 大小随机 + 平滑，vy 恒定向下）
// ==========================================================
std::pair<int, int> Behavior_JinJun(Enemy* e) {

    // 每个敌机有自己独立的 vx 曲线
    if (!jinCurrentVx.count(e)) {
        jinCurrentVx[e] = 0.0f;
        jinTargetVx[e] = 0.0f;
    }

    float& cur = jinCurrentVx[e];
    float& tgt = jinTargetVx[e];

    // 左右边界反转 vx 符号
    if (e->coord.first - e->rad <= 0) {
        cur = std::fabs(cur);
        tgt = std::fabs(tgt);
    }
    else if (e->coord.first + e->rad >= ScreenX) {
        cur = -std::fabs(cur);
        tgt = -std::fabs(tgt);
    }

    // 小概率更新随机目标速度（更自然）
    std::uniform_real_distribution<float> prob(0.0f, 1.0f);
    if (prob(gen) < 0.03f) {
        std::uniform_real_distribution<float> dist(1.0f, 4.0f);
        float newSpeed = dist(gen);
        tgt = (cur >= 0 ? newSpeed : -newSpeed);
    }

    // 平滑逼近目标速度
    cur += (tgt - cur) * 0.1f;

    int base = (sqrt(e->vx * e->vx + e->vy * e->vy)) * CalculateCoef(e);
    int vx = static_cast<int>(cur * base);
    int vy = base;

    return { vx, vy };
}



// ==========================================================
// 统一移动入口：唯一更新坐标
// ==========================================================
std::pair<int, int> CalculateEnemy(Enemy* e, Player* p) {

    std::pair<int, int> step{ 0, 0 };

    switch (e->modol) {
    case 0: step = Behavior_FengZheng(e); break;
    case 1: step = Behavior_JianMie(e, p); break;
    case 2: step = Behavior_JinJun(e); break;
    }

    // SystemMove 负责统一处理边界 / 撞墙等
    e->coord = SystemMove(e->coord, step.first, step.second);

    return e->coord;
}
