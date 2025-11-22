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
	const int CD;

	pair<int,int> NowCoord;

	prop();//type

	//移动计算 仅需计算vx vy 具体由SystemMove统一接口实现 vx自己rand可正可负 vy要保证是正的
	void OnMove();

	//碰撞检测 只需要实现如果撞上了 放音效等 具体由IsCrash统一接口实现
	void OnCrash();

	//出界检测 只需实现如果出界了... 具体由IsOutRange统一接口实现
	void OnOutRange();

	// 道具销毁 仅需实现消失动画等 delete由统一接口实现
	void OnDestroy();
};
#endif //AIRPLANE_WARS_PROP_H
