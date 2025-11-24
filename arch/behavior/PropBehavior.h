#ifndef AIRPLANE_WARS_PROPBEHAVIOR_H
#define AIRPLANE_WARS_PROPBEHAVIOR_H
#include "core/prop.h"
//生成那种道具
int RandomType(prop*p);
//随机生成坐标
std::pair<int,int>RandomProduceCoord(prop*p);
//道具的随即移动
std::pair<int,int>RandonMove(prop*p);


#endif //AIRPLANE_WARS_PROPBEHAVIOR_H