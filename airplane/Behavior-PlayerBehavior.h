#pragma once
#ifndef AIRPLANE_WARS_PLAYERBEHAVIOR_H
#define AIRPLANE_WARS_PLAYERBEHAVIOR_H
#include "core-plane.h"
#include <utility>
#include"core-Player.h"
#include<vector>
//根据选择的皮肤改变玩家皮肤编号
int ChangePlayerSkin(Player* p);

//根据皮肤更改玩家参数  0--高血量 1--高攻击 2--高速度 3--均衡  tuple--0:maxHp 1:AddATK 2:speed
std::tuple<int, int, double> ChangePlayerParam(Player* p);

//从easyx中读移动坐标
std::pair<double, double>GetPlayerCoord(Player* p);

//玩家生成位置
std::pair<double, double>ProducePlayer(Player* p);

#endif //AIRPLANE_WARS_PLAYERBEHAVIOR_H