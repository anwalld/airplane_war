#include "EnemyManager.h"
#include<vector>
#include <algorithm>
#include "behavior/EnemyBehavior.h"
#include "core/Enemy.h"
EnemyManager::EnemyManager() {}
void EnemyManager::Produce() {
	Enemy* e=new Enemy();
	e->coord=RandomLocationProduce(e);
	e->modol=RandomModol(e);
	e->type=RandomType(e);
	e->NowHp=e->maxHp=MaxHpMatchType(e);
	e->rad=RadMatchType(e);
	e->camp=1;
	enemies.push_back(e);
}

void EnemyManager::Update() {
	enemies.erase(
		std::remove_if(enemies.begin(), enemies.end(),
		[](Enemy*e) {
			if (e->NowHp<=0) {
				AllKindDestroy(e);
				return true;
			}
			else return false;
		}),enemies.end()
		);
	for (auto&ee : enemies) {
		ee->coord=CalculateEnemy(ee);
	}
}
void EnemyManager::Render() {

}
void EnemyManager::GC() {

}



