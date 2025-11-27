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
	int modol=0; // 0:风筝；1:歼灭；2:进军
	int type=0;  // 0:小怪；1:精英怪；2:boss
	double vx=5;
	double vy=2;
	const double speed = 3.5;
};
#endif //AIRPLANE_WARS_ENEMY_H
