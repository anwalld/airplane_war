// Player.h
#ifndef AIRPLANE_WARS_PLAYER_H
#define AIRPLANE_WARS_PLAYER_H

#include "plane.h"

class Player : public plane {
public:
    int speed=200/120;              // 每帧可移动的像素

    void OnHit(bool damage);     // 播放受击效果
    void OnDestroy(int NowHp); // 播放死亡动画
};

#endif
