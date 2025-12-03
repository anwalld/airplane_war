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

	int rad = 20;
	int app=0;

	double vx=0;
	double vy=0;

	int ATK=15, Type=0;//子弹的攻击力和类型----类型：0：直线子弹，1：任意角度斜子弹，2：跟踪子弹
	int camp=0;//所有玩家的标为0 敌人的标为1
	bool alive=false;
};

#endif //AIRPLANE_WARS_BULLET_H
