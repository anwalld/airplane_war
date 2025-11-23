#include "manager/PlayerManager.h"
#include "system/engine.h"
#include "behavior/PlayerBehavior.h"
#include"system/view.h"
PlayerManager::PlayerManager() {}
void PlayerManager::Produce() {
	Player*player=new Player();
	player->coord=ProducePlayer(player);
	player->NowHp=player->maxHp=100;
	players.push_back(player);
}
void PlayerManager::Update() {
	for (auto& player : players) {
		if (player->NowHp<=0) {GameOverView();}
		player->coord=CalcuPlayerMove(player);
	}
}
void PlayerManager::Render() {

}
void PlayerManager::GC() {

}
