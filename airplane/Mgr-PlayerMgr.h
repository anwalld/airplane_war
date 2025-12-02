#pragma once
#ifndef AIRPLANE_WARS_PLAYER_MANAGER_H
#define AIRPLANE_WARS_PLAYER_MANAGER_H

#include "core-Player.h"
#include <vector>
#include"easyx.h"
#include"graphics.h"
class PlayerManager {
public:
	std::vector<Player*> players;
	PlayerManager();
	void LoadingPlayerImages();
	void Produce();
	void Update();
	void Render();
	void GC();
};


#endif
