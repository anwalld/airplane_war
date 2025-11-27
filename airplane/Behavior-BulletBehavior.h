#pragma once
#ifndef AIRPLANE_WARS_BULLETBEHAVIOR_H
#define AIRPLANE_WARS_BULLETBEHAVIOR_H
#include "core-bullet.h"
#include"core-Enemy.h"
#include"core-Player.h"
#include<tuple>
//随机出外观
int AppMatchEnemyType(bullet* b);
//随机出攻击力和类型
std::tuple<int, int, int>RandomAtkAndTypeAndRad(Enemy* e, bullet* b);
//直线子弹vx vy
std::pair<double, double> LineBullet(bullet* b);
//斜线子弹vx vy
std::pair<double, double> BiasBullet(bullet* b);
//跟踪子弹vx vy
std::pair<double, double> TracedBullet(bullet* b, Player* p);
//根据vx vy调用SystemMove;
std::pair<double, double> CalcuBulletMove(bullet* b,Player*p);


#endif //AIRPLANE_WARS_BULLETBEHAVIOR_H