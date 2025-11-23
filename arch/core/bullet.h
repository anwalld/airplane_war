#ifndef AIRPLANE_WARS_BULLET_H
#define AIRPLANE_WARS_BULLET_H
#include <utility>
#include "system.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class bullet {
public:
	pair<int,int> NowCoord;

	int rad=32;
	int app;

	int vx;
	int vy;

	const int ATK=10;
	int Myself;//所有玩家的标为0 敌人的标为1

	bullet();//initCoord--planeCoord ATK--planeAtk Myself--planeKind
};
#endif //AIRPLANE_WARS_BULLET_H
