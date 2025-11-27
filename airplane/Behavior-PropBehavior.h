#pragma once
#ifndef AIRPLANE_WARS_PROPBEHAVIOR_H
#define AIRPLANE_WARS_PROPBEHAVIOR_H
#include "core-prop.h"
//生成那种道具
int RandomType(prop* p);
//随机生成坐标
std::pair<double, double>RandomProduceCoord(prop* p);
//计算落叶移动速度
std::pair<double, double>LeaveMoveVxAndVy(prop* p);
//根据速度计算移动速度
std::pair<double, double>PropMoveCoord(prop* p);

#endif //AIRPLANE_WARS_PROPBEHAVIOR_H