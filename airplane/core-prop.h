#pragma once
#ifndef AIRPLANE_WARS_PROP_H
#define AIRPLANE_WARS_PROP_H
#include <utility>
#include "system-system.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class prop {
public:
	int type = 0;
	const int CD = 10;
	int camp = 0;//阵营0表示为玩家阵营
	int rad = 100;
	bool alive = true;
	double vx, vy, speed=7;
	pair<double, double> NowCoord;

};
#endif //AIRPLANE_WARS_PROP_H

