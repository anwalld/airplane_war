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
	for (Player* player:players) {
		if (player->NowHp >= 0) {
			auto [x, y] = GetPlayerCoord(player);
			player->coord.first = x;
			player->coord.second = y;
		}
	}
}
void PlayerManager::Render() {
	Resourse res;
	int idx = players[0]->skin;
	if (idx >= 0 && idx < res.PlayerImgs.size()) {
		int x = (int)(players[0]->coord.first - 1.0 * players[0]->rad / 2);
		int y = (int)(players[0]->coord.second - 1.0 * players[0]->rad / 2);

		putimage(x, y, &res.PlayerImgs[idx]);
	}


}
void PlayerManager::GC() {

}

