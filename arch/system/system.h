#ifndef AIRPLANE_WARS_ARCH_SYSTEM_H
#define AIRPLANE_WARS_ARCH_SYSTEM_H
#include <utility>
using std::pair;

//根据当前坐标和vx vy 算出一帧后的坐标
pair<int,int>SystemMove(pair<int,int>NowCoord,int vx,int vy);

//碰撞检查 根据两个物体的坐标 和判定圆半径 检测是否碰撞
bool IsCrash(pair<int,int>NowCoordA,int R1,pair<int,int>NowCoordB,int R2);

//出界检查
bool IsOutRange(pair<int,int>NowCoord);

//判断是否应该销毁 销毁
template<typename T>
void AllKindDestroy(T* obj);

#endif //AIRPLANE_WARS_ARCH_SYSTEM_H