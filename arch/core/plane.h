#ifndef AIRPLANE_WARS_PLANE_H
#define AIRPLANE_WARS_PLANE_H

#include <utility>
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;

class plane {
public:
	int rad;//大小和判定圆
	int MaxHp;

	int NowHp;
	pair<int,int> coord;
	int vShoot;

	bullet* planeBullet;
	prop* planeProp;

	int shootAtk = 0;

	int Myself;//所有玩家的标为0 敌人的标为1

	// 这些行为全部由 Manager 调用
	virtual void OnMove() = 0;
	virtual void OnCrash() = 0;
	virtual void OnOutRange() = 0;
	virtual void OnDestroy() = 0;

	virtual ~plane() = default;
};

#endif //AIRPLANE_WARS_PLANE_H
