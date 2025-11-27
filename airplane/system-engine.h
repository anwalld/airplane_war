#pragma once

#ifndef AIRPLANE_WARS_ARCH_ENGINE_H
#define AIRPLANE_WARS_ARCH_ENGINE_H

class AllGame {
public:
	int bgm = 0;//放哪首bgm
	int dif = 0;//玩家选择难度(随游戏时间自动增加)
	int map = 0;//哪张地图
	int vo = 0;//音量
	int se = 0;//音效
	int skin = 0;//皮肤

	int AllKill = 0;//杀了多少敌机
	int GameTime = 0;//游戏时间(s)
	int ScreenX = 1920, ScreenY = 1080;
	int frameCount = 0;//游戏时间(帧)
	bool Stop = false;
	double coef = 0;//难度系数

	static AllGame& instance() {
		static AllGame obj;
		return obj;
	}

	//实时改变游戏时间
	void ChangeGameTime();

	//根据游戏时间 实时改变dif 要求该函数应该保证单调递增
	int ChangeDifWithTime();
	//计算难度系数
	double CalculateCoef();
};

#endif //AIRPLANE_WARS_ARCH_ENGINE_H


