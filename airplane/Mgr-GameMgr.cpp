#include"Mgr-GameMgr.h"
GameManager::GameManager() {
	LoadingImages();
}
void GameManager::LoadingImages() {
	playerMgr.LoadingPlayerImages();
	enemyMgr.LoadEnemyImages();
	bulletMgr.LoadResources();
	propMgr.LoadPropImages();
}
void GameManager::Update() {
	propMgr.Update(bulletMgr,enemyMgr,playerMgr.players[0]);
	bulletMgr.Update(playerMgr.players, enemyMgr.enemies);
	playerMgr.Update();
	enemyMgr.Update(playerMgr.players[0]);
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

