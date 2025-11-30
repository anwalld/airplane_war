#include "Mgr-PlayerMgr.h"
#include "system-engine.h"
#include "Behavior-PlayerBehavior.h"
#include"system-view.h"
#include"system-system.h"
PlayerManager::PlayerManager(){
	LoadingPlayerImages();
}
void PlayerManager::LoadingPlayerImages() {
	player_images.reserve(4);			//加载玩家飞机图片
	loadimage(&player_images[0], ""); //玩家飞机1
	loadimage(&player_images[1], ""); //玩家飞机2
	loadimage(&player_images[2], ""); //玩家飞机3
	loadimage(&player_images[3], ""); //玩家飞机4
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
	if (PlayerManager::IsProduce == false) {
		PlayerManager::Produce();
		IsProduce = true;
	}
	for (auto& player : players) {
		if (player->NowHp <= 0) { AllKindDestroy(player); }
		player->coord = GetPlayerCoord(player);
	}
}
void PlayerManager::Render() {

}
void PlayerManager::GC() {

}

