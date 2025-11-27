#pragma once
#ifndef AIRPLANE_WARS_BULLET_H
#define AIRPLANE_WARS_BULLET_H
#include <utility>
#include "core-plane.h"
#include"system-system.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class bullet {
public:
	pair<double, double> NowCoord;

	int rad = 32;
	int app;

	double vx;
	double vy;

	int ATK=15, Type;//子弹的攻击力和类型----类型：0：直线子弹，1：任意角度斜子弹，2：跟踪子弹
	int camp;//所有玩家的标为0 敌人的标为1
	bool alive;
};

#endif //AIRPLANE_WARS_BULLET_H
