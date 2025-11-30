#pragma once
#ifndef AIRPLANE_WARS_ENEMY_MANAGER_H
#define AIRPLANE_WARS_ENEMY_MANAGER_H

#include <vector>
#include "core-Enemy.h"
#include "system-system.h"
#include "easyx.h"
#include "graphics.h"
class EnemyManager {
public:
	std::vector<Enemy*> enemies;
	std::vector<IMAGE> enemy_images;
	EnemyManager();
	void LoadEnemyImages();
	void Produce();
	void Update(Player*p);
	void Render();
	void GC();
};


#endif
