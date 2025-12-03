#include"Mgr-GameMgr.h"
void GameManager::Update() {
	playerMgr.Update();
	enemyMgr.Update(playerMgr.players[0]);
	bulletMgr.Update(playerMgr.players, enemyMgr.enemies);
	propMgr.Update(bulletMgr,enemyMgr,playerMgr.players[0]);
}
void GameManager::Render() {
	static Resourse res;
	putimage(0, 0, &res.GameBG);

	playerMgr.Render();
	enemyMgr.Render();
	bulletMgr.Render();
	propMgr.Render();
}


void GameManager::CG() {
	playerMgr.GC();
	enemyMgr.GC();
	bulletMgr.GC();
	propMgr.GC();
}

