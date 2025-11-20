#ifndef AIRPLANE_WARS_ARCH_PLANE_H
#define AIRPLANE_WARS_ARCH_PLANE_H

#include <utility>
#include "plane.h"
using std::pair;
class plane;
class bullet;
class prop;
class Player;
class Enemy;

class Player : public plane {
public:
    Player(int r, int mhp);

    //从easyx获取vx vy 具体由SystemMove统一接口实现
    void OnMove() override;

    //碰撞检测 只需要实现如果撞上了 放音效等 具体由IsCrash统一接口实现
    void OnCrash() override;

    //出界检测 只需实现如果出界了撤回玩家的移动等 具体由IsOutRange统一接口实现
    void OnOutRange() override;

    // 玩家飞机销毁 仅需实现消失动画等 delete由统一接口实现
    void OnDestroy() override;
};

#endif // AIRPLANE_WARS_ARCH_PLANE_H
