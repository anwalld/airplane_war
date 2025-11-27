#pragma once
#ifndef AIRPLANE_WARS_SYSTEM_H
#define AIRPLANE_WARS_SYSTEM_H

#include<time.h>
#include<Windows.h>
#include <utility>
using std::pair;
//计算移动后坐标
pair<double, double> SystemMove(pair<double, double> NowCoord, double vx, double vy);
//检测是否碰撞
bool IsCrash(pair<double, double> NowCoordA, int R1, pair<double, double> NowCoordB, int R2);
//检测是否出界
bool IsOutRange(pair<double, double> NowCoord);
//检测是否同阵营
bool IsSameCamp(int A, int B);
//通用删除函数
template<typename T>
void AllKindDestroy(T* obj) {
	if (!obj) return;
	delete obj;
}
//锁定120fps
void lock120fps();
//生成a到b之间的随机整数
int RandomInt(int a, int b);
//生成a到b之间的随机小数
double RandomDouble(double a, double b);
#endif //AIRPLANE_WARS_SYSTEM_H
