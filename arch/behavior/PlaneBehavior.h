#ifndef AIRPLANE_WARS_PLANEMANAGER_H
#define AIRPLANE_WARS_PLANEMANAGER_H
#include "core/plane.h"
#include "system/engine.h"

//根据当前游戏时间和飞机射速判断本帧是否开火
bool ShouldFire(plane*p);

#endif //AIRPLANE_WARS_PLANEMANAGER_H