#pragma once
#ifndef AIRPLANE_WARS_ENEMYBEHAVIOR_H
#define AIRPLANE_WARS_ENEMYBEHAVIOR_H
#include "core-Enemy.h"
//上1/4屏幕随机位置生成敌人
std::pair<double, double>RandomLocationProduce(Enemy* e);

//根据难度系数计算敌人模型和类型
std::pair<int, int>RandomModelAndTypeWithCoef(Enemy*e);
//根据Type匹配固定的判定圆半径
int RadMatchType(Enemy* e);

//根据Type匹配固定血量
int MaxHpMatchType(Enemy* e);

//first--vx;second--vy
std::pair<double, double> Behavior_FengZheng(Enemy* e);
std::pair<double, double> Behavior_JianMie(Enemy* e, Player* p);
std::pair<double, double> Behavior_JinJun(Enemy* e);

//调用SystemMove
std::pair<double, double> CalculateEnemy(Enemy* e, Player* p);

#endif //AIRPLANE_WARS_ENEMYBEHAVIOR_H