#ifndef AIRPLANE_WARS_ENEMY_MANAGER_H
#define AIRPLANE_WARS_ENEMY_MANAGER_H

#include <vector>
#include "../core/Enemy.h"
#include "../system/system.h"

class EnemyManager {
public:

	std::vector<Enemy*> enemies;

	// 难度控制敌机生成数量
	void Produce(int dif);

	void AddEnemy(Enemy* e) { enemies.push_back(e); }

	void Update(Player* player);
	void Render();
	void GC();
};

#endif
