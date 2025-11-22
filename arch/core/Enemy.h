#ifndef AIRPLANE_WARS_ENEMY_H
#define AIRPLANE_WARS_ENEMY_H
#include <utility>
#include "plane.h"
using std::pair;

class bullet;
class prop;
class Player;
class Enemy;
class plane;

class Enemy : public plane {
public:
	const int modol; // 0:风筝；1:歼灭；2:进军
	const int type;  // 0:小怪；1:精英怪；2:boss

	Enemy();//Nowcoord--RandomProduce;model和type--InitData;rad--ConstSide;

	void OnHit(bool damage);     // 播放受击效果
	void OnDestroy(bool damage);           // 播放死亡动画


};
#endif //AIRPLANE_WARS_ENEMY_H
