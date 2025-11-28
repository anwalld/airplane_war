#include "Mgr-EnemyMgr.h"
#include<vector>
#include <algorithm>
#include "Behavior-EnemyBehavior.h"
#include "core-Enemy.h"
#include"system-engine.h"
static bool IsProduce() {
	//根据AllGame::instance().coef得出生成敌机概率 根据这个概率判断本帧是否生成敌机
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
	enemies.push_back(e);
}

void EnemyManager::Update(Player*p) {
	if (IsProduce())EnemyManager::Produce();
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
			[](Enemy* e) {
				if (e->NowHp <= 0) {
					AllGame::instance().AllKill++;
					AllKindDestroy(e);
					return true;
				}
				else return false;
			}), enemies.end()
				);
	for (auto& ee : enemies) {
		ee->coord = CalculateEnemy(ee,p);
	}
}
void EnemyManager::Render() {

}
void EnemyManager::GC() {

}



