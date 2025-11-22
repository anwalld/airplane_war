#ifndef AIRPLANE_WARS_PLAYER_MANAGER_H
#define AIRPLANE_WARS_PLAYER_MANAGER_H

#include "../core/Player.h"

class PlayerManager {
public:
	Player* player;

	PlayerManager();

	void Update();
	void Render();
	void GC();
};

#endif
