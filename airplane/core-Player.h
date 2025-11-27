#pragma once
#ifndef AIRPLANE_WARS_PLAYER_H
#define AIRPLANE_WARS_PLAYER_H

#include "core-plane.h"

class Player : public plane {
public:
    double speed = 200 / 120;              // 每帧可移动的像素
	int AddATK = 5;					   // 额外攻击力
};


#endif
