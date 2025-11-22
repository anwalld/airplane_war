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
	const int Coef;

	Enemy(int r, int mhp, int m, int t);//Nowcoord--RandomProduce;model和type--InitData;Coef--CalcuCoef;rad--ConstSide;

	//根据dif GameTime AllKill算个系数赋给Coef
	int CalcuCoef(const int GameTime,const int AllKill,const int dif);

	//根据Coef随机出model和type first--model  second--type
	pair<int,int> InitModelAndType(int dif);

	//根据type弄出3个固定的大小
	int ConstSide();

	//在屏幕上1/4处的随机位置生成敌机
	pair<int,int>RandomProduce();

	//实现行为模式的具体逻辑需要返回vx(first)和vy(second)
	pair<int,int> ModelAttack();

	//接收ModelAttack返回的vx vy 调用SystemMove
	void OnMove() override;

	//碰撞检测 只需要实现如果撞上了 放音效等 具体由IsCrash统一接口实现
	void OnCrash() override;

	//出界检测 只需实现如果出界了撤回敌机的移动等 具体由IsOutRange统一接口实现
	void OnOutRange() override;

	// 敌机销毁 仅需实现 死于玩家加分，消失动画等 delete由统一接口实现
	void OnDestroy() override;
};
#endif //AIRPLANE_WARS_ENEMY_H
