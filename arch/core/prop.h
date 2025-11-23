#ifndef AIRPLANE_WARS_PROP_H
#define AIRPLANE_WARS_PROP_H
#include <utility>
#include "system.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class prop {
public:
	int type=0;
	const int CD=10;
	int camp=0;//阵营0表示为玩家阵营

	pair<int,int> NowCoord;

};
#endif //AIRPLANE_WARS_PROP_H
