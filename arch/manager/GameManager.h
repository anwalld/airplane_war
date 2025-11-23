#ifndef AIRPLANE_WARS_GAME_MANAGER_H
#define AIRPLANE_WARS_GAME_MANAGER_H

#include "PlayerManager.h"
#include "EnemyManager.h"
#include "BulletManager.h"
#include "PropManager.h"
#include "../system/engine.h"

class GameManager {
public:
	PlayerManager playerMgr;
	EnemyManager enemyMgr;
	BulletManager bulletMgr;
	PropManager propMgr;
	AllGame engine;

	void Update();
	void Render();
};


#endif
