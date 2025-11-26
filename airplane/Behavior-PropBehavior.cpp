#include "system-system.h"
#include<random>
#include"Behavior-PropBehavior.h"
#include"system-engine.h"
#include<unordered_map>
static std::random_device rd;
static std::mt19937 gen(rd());

int RandomType(prop* p) {
	int x = 3;
	std::uniform_int_distribution<int> dis(0, x - 1);
	int ans = dis(gen);
	return ans;
}

std::pair<int, int>RandomProduceCoord(prop* p) {
	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// 左右范围：[rad, screenX - rad]
	std::uniform_int_distribution<int> disX(p->rad, screenX - p->rad);

	// 上 1/4 的高度：范围 [rad, screenY/4 - rad]
	int topQuarter = screenY / 4;
	std::uniform_int_distribution<int> disY(p->rad, topQuarter - p->rad);

	int x = disX(gen);
	int y = disY(gen);

	p->NowCoord = { x, y };
	return p->NowCoord;


}

std::pair<int, int>RandonMove(prop* p) {
	static std::unordered_map<prop*, float> curVx;
	static std::unordered_map<prop*, float> tgtVx;

	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// 初始化
	if (!curVx.count(p)) {
		curVx[p] = 0.0f;
		tgtVx[p] = 0.0f;
	}

	float& vx_now = curVx[p];
	float& vx_tgt = tgtVx[p];

	// 边界反弹
	if (p->NowCoord.first - p->rad <= 0) {
		vx_now = std::fabs(vx_now);
		vx_tgt = std::fabs(vx_tgt);
	}
	else if (p->NowCoord.first + p->rad >= screenX) {
		vx_now = -std::fabs(vx_now);
		vx_tgt = -std::fabs(vx_tgt);
	}

	// 小概率变化目标速度
	std::uniform_real_distribution<float> prob(0.0f, 1.0f);
	if (prob(gen) < 0.03f) {
		std::uniform_real_distribution<float> dist(0.5f, 3.0f);
		float newV = dist(gen);

		// 保留方向
		vx_tgt = (vx_now >= 0 ? newV : -newV);
	}

	// 速度平滑变化
	vx_now += (vx_tgt - vx_now) * 0.1f;

	// 纵向速度（恒定向下）
	float vy = 10;

	// 计算移动
	int newX = p->NowCoord.first + static_cast<int>(vx_now);
	int newY = p->NowCoord.second + static_cast<int>(vy);

	p->NowCoord = { newX, newY };
	return p->NowCoord;
}