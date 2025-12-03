#pragma once

#ifndef AIRPLANE_WARS_ARCH_VIEW_H
#define AIRPLANE_WARS_ARCH_VIEW_H
#include"easyx.h"
#include"graphics.h"
#include"Mgr-GameMgr.h"
void SettingsView();

void PrintTeamIntroduction();

void Instructions();



int ChoosePlane();


void PrintGameScene(const GameManager& g);//载入战机图片 bgm 和飞机的数值

void GameOverView();//展示得分
void MenuView();
void GameView();

#endif //AIRPLANE_WARS_ARCH_VIEW_H