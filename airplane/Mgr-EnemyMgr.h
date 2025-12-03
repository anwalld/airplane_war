#pragma once
#ifndef AIRPLANE_WARS_ENEMY_MANAGER_H
#define AIRPLANE_WARS_ENEMY_MANAGER_H

#include <vector>
#include "core-Enemy.h"
#include "system-system.h"
#include "easyx.h"
#include "graphics.h"
#include"Res-GameRes.h"
class EnemyManager {
public:
	std::vector<Enemy*> enemies;
	void Produce();
	void Update(Player*p);
	void Render();
	void GC();
};


#endif
