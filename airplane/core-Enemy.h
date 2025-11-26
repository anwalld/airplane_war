#pragma once
#ifndef AIRPLANE_WARS_ENEMY_H
#define AIRPLANE_WARS_ENEMY_H
#include <utility>
#include "core-plane.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class Enemy : public plane {
public:
	int modol; // 0:风筝；1:歼灭；2:进军
	int type;  // 0:小怪；1:精英怪；2:boss
	int vx;
	int vy;

};
#endif //AIRPLANE_WARS_ENEMY_H
