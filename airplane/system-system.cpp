
#include <utility>
#include "system-system.h"
#include "system-engine.h"
#include <chrono>
#include <windows.h>
#include<random>
using std::pair;

//通用移动计算函数
pair<double, double>SystemMove(pair<double, double>NowCoord, double vx, double vy) {
    double AfterCoordX = NowCoord.first + vx;
    double AfterCoordY = NowCoord.second +vy;
	return std::make_pair(AfterCoordX, AfterCoordY);
}

//判断是否碰撞
bool IsCrash(pair<double, double>NowCoordA, int R1, pair<double, double>NowCoordB, int R2) {
    double DisSquare = (NowCoordA.first - NowCoordB.first) * (NowCoordA.first - NowCoordB.first) + (NowCoordA.second - NowCoordB.second) * (NowCoordA.second - NowCoordB.second);
    double RDisSquare = (R1 + R2) * (R1 + R2);
	return RDisSquare >= DisSquare;
}

//判断是否出界
bool IsOutRange(pair<double, double>NowCoord) {
	return NowCoord.first<0 || NowCoord.first>AllGame::instance().ScreenX || NowCoord.second<0 || NowCoord.second>AllGame::instance().ScreenY;
}

//敌我识别函数
bool IsSameCamp(int A, int B) {
	return A == B;
}
//锁定120fps
void lock120fps()
{
    static auto last = std::chrono::high_resolution_clock::now(); // 上一帧结束时间

    auto now = std::chrono::high_resolution_clock::now();         // 当前帧结束时间

    double delta = std::chrono::duration<double>(now - last).count(); // 本帧耗时

    const double target = 1.0 / 120.0;  // 每帧目标耗时

    if (delta < target)
    {
        double sleepTime = target - delta;
        Sleep((DWORD)(sleepTime * 1000));
    }

    last = std::chrono::high_resolution_clock::now(); // 更新“上一帧结束时间”
}
//生成a到b之间的随机整数
int RandomInt(int a, int b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);
    return dist(gen);
}
//生成a到b之间的随机小数
double RandomDouble(double a, double b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dist(a, b);
    return dist(gen);
}


