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
	int Vbullet;
	int rad;
	int app;

	pair<int,int> InitCoord;
	double k;

	const int ATK;
	int Myself;//所有玩家的标为0 敌人的标为1

	bullet();//initCoord--planeCoord ATK--planeAtk Myself--planeKind

	// 根据输入的 app 算出唯一 int，再从资源库中掉出贴图
	int MatchAppreciation(int app);

	//移动计算 仅需计算 vx,vy 具体由SystemMove统一接口实现
	void OnMove();

	//碰撞检测 如果撞上了&&子弹不来源与友方 去实现放音效 扣血 特效等 具体由IsCrash统一接口实现
	void OnCrash();

	//出界检测 只需实现如果出界了... 具体由IsOutRange统一接口实现
	void OnOutRange();

	// 子弹销毁 仅需实现消失动画等 delete由统一接口实现
	void OnDestroy();
};
#endif //AIRPLANE_WARS_BULLET_H
