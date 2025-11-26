#pragma once
#ifndef AIRPLANE_WARS_GAME_MANAGER_H
#define AIRPLANE_WARS_GAME_MANAGER_H

#include "Behavior-PlayerBehavior.h"
#include "Mgr-EnemyMgr.h"
#include "Mgr-BulletMgr.h"
#include "Mgr-PropMgr.h"
#include "Mgr-PlayerMgr.h"
#include "system-engine.h"

class GameManager {
public:
	PlayerManager playerMgr;
	EnemyManager enemyMgr;
	BulletManager bulletMgr;
	PropManager propMgr;

	void Update();
	void Render();
	void CG();
};


#endif
