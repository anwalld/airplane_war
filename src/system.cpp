
#include <utility>
#include "system/system.h"
#include "system/engine.h"
using std::pair;

//根据当前坐标和vx vy 算出一帧后的坐标
pair<int,int>SystemMove(pair<int,int>NowCoord,int vx,int vy) {
	int AfterCoordX=NowCoord.first+static_cast<int>(vx*1000*1.0/120);
	int AfterCoordY=NowCoord.second+static_cast<int>(vy*1000*1.0/120);
	return std::make_pair(AfterCoordX,AfterCoordY);
}

//碰撞检查 根据两个物体的坐标 和判定圆半径 检测是否碰撞
bool IsCrash(pair<int,int>NowCoordA,int R1,pair<int,int>NowCoordB,int R2) {
	int DisSquare=(NowCoordA.first-NowCoordB.first)*(NowCoordA.first-NowCoordB.first)+(NowCoordA.second-NowCoordB.second)*(NowCoordA.second-NowCoordB.second);
	int RDisSquare=(R1+R2)*(R1+R2);
	return RDisSquare>=DisSquare;
}

//出界检查
bool IsOutRange(pair<int,int>NowCoord) {
	return NowCoord.first<0||NowCoord.first>AllGame::instance().ScreenX||NowCoord.second<0||NowCoord.second>AllGame::instance().ScreenY;
}

//判断是否应该销毁 销毁
template<typename T>
void AllKindDestroy(T* obj) {
	delete obj;
}
