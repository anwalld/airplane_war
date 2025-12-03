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
	Player* p = players[0];

	int idx = p->skin;
	if (idx < 0 || idx >= res.PlayerImgs.size())
		return;

	// 贴图目标大小 = 玩家判定圆直径
	int w = p->rad * 2;
	int h = p->rad * 2;

	// 中心点坐标 → 左上角
	int x = (int)(p->coord.first - p->rad);
	int y = (int)(p->coord.second - p->rad);

	drawAlphaResize(x, y, w, h, &res.PlayerImgs[idx]);
}

void PlayerManager::GC() {

}

