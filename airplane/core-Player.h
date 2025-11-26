#pragma once
#ifndef AIRPLANE_WARS_PLAYER_H
#define AIRPLANE_WARS_PLAYER_H

#include "core-plane.h"

class Player : public plane {
public:
    int speed = 200 / 120;              // 每帧可移动的像素
};


#endif
