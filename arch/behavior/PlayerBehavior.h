#ifndef AIRPLANE_WARS_PLAYERBEHAVIOR_H
#define AIRPLANE_WARS_PLAYERBEHAVIOR_H
#include "core/Player.h"
//从easyx中读移动坐标
std::pair<int,int>CalcuPlayerMove(Player* p);

//玩家生成位置
std::pair<int,int>ProducePlayer(Player* p);

#endif //AIRPLANE_WARS_PLAYERBEHAVIOR_H