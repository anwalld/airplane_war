
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

void drawAlpha(int  picture_x, int picture_y, IMAGE* picture) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD* dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD* draw = GetImageBuffer();
	DWORD* src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}

