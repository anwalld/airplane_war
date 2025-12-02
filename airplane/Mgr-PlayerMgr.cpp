#include "Mgr-PlayerMgr.h"
#include "system-engine.h"
#include "Behavior-PlayerBehavior.h"
#include"system-view.h"
#include"system-system.h"
PlayerManager::PlayerManager(){
	PlayerManager::Produce();
}
void PlayerManager::Produce() {
	Player* player = new Player();
	player->coord = ProducePlayer(player);
	auto [a, b, c] = ChangePlayerParam(player);
	player->NowHp = player->maxHp = a;
	player->AddATK = b;
	player->speed = c;
	players.push_back(player);
}
void PlayerManager::Update() {
	// Iterate with iterator to safely delete and erase dead players without accessing dangling pointers
	for (auto it = players.begin(); it != players.end();) {
		Player* player = *it;
		if (!player) {
			it = players.erase(it);
			continue;
		}
		if (player->NowHp <= 0) {
			AllKindDestroy(player);
			it = players.erase(it);
			continue;
		}
		player->coord = GetPlayerCoord(player);
		++it;
	}
}
void PlayerManager::Render() {

}
void PlayerManager::GC() {

}

