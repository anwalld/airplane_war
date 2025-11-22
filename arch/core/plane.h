// plane.h
#ifndef AIRPLANE_WARS_PLANE_H
#define AIRPLANE_WARS_PLANE_H

#include <utility>
using std::pair;

class plane {
public:
	int    rad = 100;               // 判定圆半径
	int    maxHp = 0;
	int    NowHp = 0;
	pair<int,int> coord;    // 坐标
	int    Vshoot= 10;     // 射击间隔（帧数）
	int    atk = 10;               // 子弹伤害
	int    FromWho = 0;              // 0: 玩家；1: 敌机

	virtual ~plane() = default;
};

#endif
