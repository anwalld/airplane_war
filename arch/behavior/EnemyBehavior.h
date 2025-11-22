#ifndef AIRPLANE_WARS_ENEMYBEHAVIOR_H
#define AIRPLANE_WARS_ENEMYBEHAVIOR_H
#include "core/Enemy.h"
//计算coef
int CalculateCoef(Enemy*e);

//按概率随机出modol
int RandomModol(Enemy*e);

//按概率随机出type
int RandomType(Enemy*e);

//根据type匹配固定的大小
int SideMatchType(Enemy*e);

//根据Type匹配固定的判定圆半径
int RadMatchType(Enemy*e);

//first--vx;second--vy
std::pair<int,int> Behavior_FengZheng(Enemy* e);
std::pair<int,int> Behavior_JianMie(Enemy* e, Player* p);
std::pair<int,int> Behavior_JinJun(Enemy*e);

//调用SystemMove
std::pair<int,int> CalculateEnemy(pair<int,int>v,Enemy*e);


#endif //AIRPLANE_WARS_ENEMYBEHAVIOR_H