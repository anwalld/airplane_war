#pragma once
#ifndef AIRPLANE_WARS_SYSTEM_H
#define AIRPLANE_WARS_SYSTEM_H

#include<time.h>
#include<Windows.h>
#include <utility>
using std::pair;

pair<int, int> SystemMove(pair<int, int> NowCoord, int vx, int vy);

bool IsCrash(pair<int, int> NowCoordA, int R1, pair<int, int> NowCoordB, int R2);

bool IsOutRange(pair<int, int> NowCoord);

bool IsSameCamp(int A, int B);

template<typename T>
void AllKindDestroy(T* obj) {
	if (!obj) return;
	delete obj;
}
void lock120fps();
#endif //AIRPLANE_WARS_SYSTEM_H
