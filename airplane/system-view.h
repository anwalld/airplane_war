#pragma once

#ifndef AIRPLANE_WARS_ARCH_VIEW_H
#define AIRPLANE_WARS_ARCH_VIEW_H
#include"easyx.h"
#include"graphics.h"
void SettingsView();

void PrintTeamIntroduction();

void Instructions();



int ChoosePlane();/*该函数返回值决定 皮肤 MaxHp 射速等Player的性质
					实现战机选择 数值和立绘展示 以及战机选择
					-----即战备界面------*/

void PrintGameScene();//载入战机图片 bgm 和飞机的数值

void GameOverView();//展示得分
void MenuView();
void GameView();

#endif //AIRPLANE_WARS_ARCH_VIEW_H