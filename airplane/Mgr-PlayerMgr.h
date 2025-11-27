#pragma once
#ifndef AIRPLANE_WARS_PLAYER_MANAGER_H
#define AIRPLANE_WARS_PLAYER_MANAGER_H

#include "core-Player.h"
#include <vector>
class PlayerManager {
public:
	std::vector<Player*> players;
	void Produce();
	void Update();
	void Render();
	void GC();
};


#endif
