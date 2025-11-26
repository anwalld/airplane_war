#pragma once
#ifndef AIRPLANE_WARS_BULLETBEHAVIOR_H
#define AIRPLANE_WARS_BULLETBEHAVIOR_H
#include "core-bullet.h"
//随机出外观
int AppMatchEnemyType(bullet* b);

//初始化vx,vy;
std::pair<int, int>InitVyAndVy(bullet* b);

//根据vx vy调用SystemMove;
std::pair<int, int> CalcuBulletMove(pair<int, int>v, bullet* b);


#endif //AIRPLANE_WARS_BULLETBEHAVIOR_H