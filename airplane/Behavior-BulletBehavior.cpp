#include "Behavior-BulletBehavior.h"
#include <random>
#include "system-system.h"
#include"core-bullet.h"
#include"core-Enemy.h"
#include"core-Player.h"
#include<tuple>

//小怪<->子弹类型的ATK对应 ([e->type][Btype])
static const int BaseTypeAtk[3][3] = {
	{5,10,5},
	{5,15,5},
	{5,15,10}
};
//子弹半径与对应子弹类型对应
static const int BulletRad[3] = {
	25,20,15
};
//外观
int AppMatchEnemyType(Enemy* e, bullet* b) {
	switch (e->type) {
	case 0: {//小怪
		switch (b->Type) {
		case 0: return 0;//小怪-直线
		case 1: return 1;//小怪-斜线
		case 2: return 2;//小怪-跟踪
		}
		break;
	}
	case 1: {//精英怪
		switch (b->Type) {
		case 0: return 3;//精英怪-直线
		case 1: return 4;//精英怪-斜线
		case 2: return 5;//精英怪-跟踪
		}
		break;
	case 2: {//boss
		switch (b->Type) {
		case 0: return 6;//boss-直线
		case 1: return 7;//boss-斜线
		case 2: return 8;//boss-跟踪
		}
		break;
	}
	}
	}
	return 0;
}

//根据输入的input和a,b返回0,1,2三种类型
static int JustGetKind(int input,int a, int b) {
	if(input<=a)return 0;
	else if(input<=b) return 1;
	else return 2;
}

//随机出攻击力,类型,半径
std::tuple<int, int,int>RandomAtkAndTypeAndRad(Enemy* e,bullet*b) {
	int tmp = RandomInt(0, 99);
	int Btype = 0;
	switch (e->type) {
	case 0: {//小怪
		Btype = JustGetKind(tmp, 70, 95);
		break;
	}
	case 1: {//精英怪
		Btype = JustGetKind(tmp, 50, 80);
		break;
	}
	case 2: {//boss
		Btype = JustGetKind(tmp, 30, 70);
		break;
	}
	default:
		break;
	}
	int ATK = BaseTypeAtk[e->type][Btype];
	int Rad = BulletRad[Btype];
	b->ATK = ATK;
	b->Type = Btype;
	b->rad = BulletRad[Btype];
	return std::make_tuple(ATK, Btype, Rad);
}
//直线子弹vx vy
std::pair<double, double> LineBullet(bullet* b) {
		b->vx = 0.0;
		b->vy = -10.0;
		if (b->camp == 0)return std::make_pair(0.0, -10.0);
		else return std::make_pair(0.0, 10);
}
//斜线子弹vx vy
std::pair<double, double> BiasBullet(bullet* b) {
	double deg = RandomDouble(-60.0, 60.0);
	double rad = deg * 3.1415926 / 180.0;
	b->vx = 7.0 * sin(rad);
	if (b->camp) {
		b->vy = 7.0 * cos(rad);
		return std::make_pair(b->vx, b->vy);
	}
	else {
		b->vy = -7.0 * cos(rad);
		return std::make_pair(b->vx, b->vy);
	}
}
//跟踪子弹vx vy
std::pair<double, double> TracedBullet(bullet* b,Player*p) {
		double dx = p->coord.first - b->NowCoord.first;
		double dy = p->coord.second - b->NowCoord.second;
		double dist = sqrt(dx * dx + dy * dy);
		double turn = 0.02; // 追踪转向速率
		b->vx = b->vx * (1 - turn) + (dx / dist) * 5.0 * turn;
		b->vy = b->vy * (1 - turn) + (dy / dist) * 5.0 * turn;

		return std::make_pair(b->vx, b->vy);
}

//根据vx vy调用SystemMove;
std::pair<double, double> CalcuBulletMove(bullet* b,Player*p) {
	switch (b->Type) {
		case 0: {//直线子弹
			pair<double, double>v = LineBullet(b);
			b->NowCoord= SystemMove(b->NowCoord, v.first, v.second);
			break;
		}
		case 1: {//斜线子弹
			pair<double, double>v = BiasBullet(b);
			b->NowCoord= SystemMove(b->NowCoord, v.first, v.second);
			break;
		}
		case 2: {//跟踪子弹
			pair<double, double>v = TracedBullet(b,p);
			b->NowCoord= SystemMove(b->NowCoord, v.first, v.second);
			break;
		}
	}
	return b->NowCoord;
}
