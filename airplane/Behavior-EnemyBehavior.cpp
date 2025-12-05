#include <cmath>
#include <random>
#include <unordered_map>
#include "Behavior-EnemyBehavior.h"
#include "system-engine.h"
#include "system-system.h"
#include"core-Player.h"
// 生成 1/4 区域内的随机坐标
std::pair<double, double> RandomLocationProduce(Enemy* e) {
    // X 轴随机范围 [e->rad, ScreenX - e->rad]
    e->coord.first = RandomDouble(e->rad,AllGame::instance().ScreenX-e->rad);

    // Y 轴随机范围 [e->rad, ScreenY/4 - e->rad]（上方 1/4 区域）
    double topQuarterHeight = 1.0* AllGame::instance().ScreenY / 4;
	e->coord.second = RandomDouble(e->rad, topQuarterHeight - e->rad);

    return e->coord;
}
//根据难度系数计算敌人模型和类型
std::pair<int, int>RandomModelAndTypeWithCoef(Enemy* e) {
    //辅助函数
    auto Lerp = [](double a, double b, double t) {
        return a + (b - a) * t;
        };
    auto ThreeChooseOneWithCoef = [Lerp](pair<double, double>a, pair<double, double>b, pair<double, double>c, double coef)->int {
        double pa = Lerp(a.first, a.second, coef);
        double pb = Lerp(b.first, b.second, coef);
        double pc = Lerp(c.first, c.second, coef);
        double sum = pa + pb + pc;
        pa /= sum;
        pb /= sum;
        pc /= sum;
        double j = RandomDouble(0, 1);
        if (j <= pa)return 0;
        else if (j <= pb+pa)return 1;
        else return 2;
        };
    // 根据 coef 计算 type
    e->type = ThreeChooseOneWithCoef({ 0.9,0 }, { 0.1,0.2 }, { 0.0,0.8 }, AllGame::instance().coef);
    // 根据 type 匹配 modol
    switch (e->type) {
    case 0: { // 小怪
        e->modol = ThreeChooseOneWithCoef(
            { 0.20, 0.05 },   // 风筝
            { 0.40, 0.45 },   // 歼灭
            { 0.40, 0.50 },   // 进军
            AllGame::instance().coef
        );
        break;
    }
    case 1: { // 精英
        e->modol = ThreeChooseOneWithCoef(
            { 0.10, 0.05 },   // 风筝
            { 0.45, 0.45 },   // 歼灭
            { 0.45, 0.50 },   // 进军
            AllGame::instance().coef
        );
        break;
    }
    case 2: { // boss
        e->modol = 0;
        break;
    }
    }    return { e->modol,e->type };
}

// 根据 Type 匹配半径
int RadMatchType(Enemy* e) {
    switch (e->type) {
    case 0: {
        e->rad = 28; 
        break;
    }
    case 1: {
        e->rad = 40; 
        break;
    }
    case 2: {
        e->rad = 55;
        break;
    }
    }
    return e->rad;
}

// 根据 Type 匹配最大 HP
int MaxHpMatchType(Enemy* e) {
    switch (e->type) {
    case 0: {
        e->maxHp = 40; break;
    }
    case 1: {
        e->maxHp = 100; break;
    }
    case 2: {
        e->maxHp = 300; break;
    }

    }
    return e->maxHp;
}
// 每个敌机独立的风筝方向
static std::unordered_map<Enemy*, int> fengzhengDir;

//风筝
std::pair<double, double> Behavior_FengZheng(Enemy* e) {

    // 初始化方向
    if (fengzhengDir.find(e) == fengzhengDir.end()) {
        fengzhengDir[e] = (RandomDouble(0, 1) < 0.5 ? -1 : 1);
    }

    int& dir = fengzhengDir[e];
    // 少量随机反转
    if (RandomDouble(0, 1) <= 0.05) { 
        dir *= -1;
    }

    // 屏幕边缘处理
    if (e->coord.first - e->rad <= 0) dir = 1;
    else if (e->coord.first + e->rad >= AllGame::instance().ScreenX) dir = -1;

    double vx = dir * (e->speed * 3);

    // 绝不能为 0
    if (vx == 0) vx = dir * 3;

    // 竖直随机
    double vy = RandomDouble(0, 0.5);

    return { vx, vy };
}

//歼灭
std::pair<double, double> Behavior_JianMie(Enemy* e, Player* p) {

    double dx = p->coord.first - e->coord.first;
    double dy = p->coord.second - e->coord.second;

    double dist = std::sqrt(dx * dx + dy * dy);
    if (dist < 1.0) dist = 1.0;

    double ux = dx / dist;
    double uy = dy / dist;

    double speedBase = e->speed * AllGame::instance().coef*100;

    double vx = ux * speedBase;
    double vy = uy * speedBase;

    // 纠正太小的 vx
    if (std::abs(vx) < 0.01 && dx > 0) vx = 0.01;
    if (std::abs(vx) < 0.01 && dx < 0) vx = -0.01;

    return { vx, vy };
}
// 每个敌机 JinJun 的随机 vx系统
static std::unordered_map<Enemy*, double> jinCurrentVx;
static std::unordered_map<Enemy*, double> jinTargetVx;
std::pair<double, double> Behavior_JinJun(Enemy* e) {
    if (jinCurrentVx.find(e) == jinCurrentVx.end()) {
        jinCurrentVx[e] = 0;
        jinTargetVx[e] = 1;
    }
    double& cur = jinCurrentVx[e];
    double& tgt = jinTargetVx[e];
    if (RandomDouble(0, 1) <= 0.05) {
        tgt = RandomDouble(-1,1);
    }
    if (e->coord.first - e->rad <= 0) {
        cur = std::fabs(cur);
        tgt = std::fabs(tgt);
    }
    else if (e->coord.first + e->rad >=AllGame::instance().ScreenX) {
        cur = -std::fabs(cur);
        tgt = -std::fabs(tgt);
    }
    cur += (tgt - cur) * 0.15;
    e->vx = e->speed * cur;
    e->vy = 1;
    return { e->vx,e->vy };
}
//移动接口
std::pair<double, double> CalculateEnemy(Enemy* e, Player* p) {

    std::pair<double, double> v;

    switch (e->modol) {
    case 0: v = Behavior_FengZheng(e); break;
    case 1: v = Behavior_JianMie(e, p); break;
    case 2: v = Behavior_JinJun(e);   break;
    }

    // SystemMove(double,double)
    e->coord = SystemMove(e->coord, v.first, v.second);

    return e->coord;
}