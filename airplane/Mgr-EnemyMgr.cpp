#include "Mgr-EnemyMgr.h"
#include<vector>
#include <algorithm>
#include "Behavior-EnemyBehavior.h"
#include "core-Enemy.h"
#include"system-engine.h"
static bool IsProduce() {
	auto Lerp = [](double a, double b, double t) {
		return a + (b - a) * t;
		};
	double min_prob = 0; // 最小生成概率
	double max_prob = 0.05; // 最大生成概率
	double current_prob = Lerp(min_prob, max_prob, AllGame::instance().coef);

	// 生成随机数并判断是否生成敌机
	double rand_val = RandomDouble(0, 1);
	return rand_val <= current_prob;
}
void EnemyManager::Produce() {
	Enemy* e = new Enemy();
	e->coord = RandomLocationProduce(e);
	auto [modol, type] = RandomModelAndTypeWithCoef(e);
	e->modol = modol;
	e->type = type;
	e->NowHp = e->maxHp = MaxHpMatchType(e);
	e->rad = RadMatchType(e);
	e->camp = 1;
	e->Vshoot = 120;
	e->alive = true;
	enemies.push_back(e);
}

void EnemyManager::Update(Player*p) {
	if (IsProduce())EnemyManager::Produce();
	for (auto& ee : enemies) {
		if (IsOutRange(ee->coord) || ee->NowHp <= 0) {
			if (ee->NowHp <= 0)AllGame::instance().AllKill++;
			ee->alive = false;
		}
		if (ee->alive == false)continue;
		ee->coord = CalculateEnemy(ee,p);
	}
}
void EnemyManager::Render() {
	Resourse res;
	for (const auto& ee : enemies) {
		int idx = ee->type;
		if (idx < 0 || idx >= res.EnemyImgs.size())
			continue;

		int w = ee->rad * 2;
		int h = ee->rad * 2;

		int x = (int)(ee->coord.first - ee->rad);
		int y = (int)(ee->coord.second - ee->rad);

		drawAlphaResize(x, y, w, h, &res.EnemyImgs[idx]);

	}

}
void EnemyManager::GC() {
	//esayx





	//kill
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
			[](Enemy* e) {
				if (!e->alive) {
					AllKindDestroy(e);
					return true;
				}
				else return false;
			}), enemies.end()
				);
}



