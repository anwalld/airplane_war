#include "manager/GameManager.h"
void GameManager::Update() {
	propMgr.Update(playerMgr.players[0]);
	bulletMgr.Update(playerMgr.players,enemyMgr.enemies);
	playerMgr.Update();
	enemyMgr.Update();
}
void GameManager::Render() {
	propMgr.Render();
	bulletMgr.Render();
	playerMgr.Render();
	enemyMgr.Render();
}
void GameManager::CG() {
	propMgr.GC();
	bulletMgr.GC();
	playerMgr.GC();
	enemyMgr.GC();
}

