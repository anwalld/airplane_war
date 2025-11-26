#pragma once
#ifndef AIRPLANE_WARS_ENEMY_MANAGER_H
#define AIRPLANE_WARS_ENEMY_MANAGER_H

#include <vector>
#include "core-Enemy.h"
#include "system-system.h"

class EnemyManager {
public:
	EnemyManager();

	std::vector<Enemy*> enemies;
	void Produce();
	void Update(Player*p);
	void Render();
	void GC();
};


#endif
