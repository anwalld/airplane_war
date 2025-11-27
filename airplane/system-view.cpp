#include"system-view.h"
#include "easyx.h"
#include"graphics.h"
#include"system-engine.h"
#include"Mgr-GameMgr.h"
#include"system-system.h"
const int WAITING = 100;//等待尺寸数值
int oper = 0;

void MenuView() {
	//新建窗口	
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();
	//设置背景图
	IMAGE MenuBackground;
	loadimage(&MenuBackground, L"", WAITING, WAITING);
	//设置标题
	settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(WAITING, WAITING, _T("\nWAR LIGHTING"));
	//设置选项
	outtextxy(WAITING, WAITING, _T("开始游戏"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	outtextxy(WAITING, WAITING, _T("游戏设置"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	outtextxy(WAITING, WAITING, _T("玩法说明"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	outtextxy(WAITING, WAITING, _T("团队介绍"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	outtextxy(WAITING, WAITING, _T("退出游戏"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	ExMessage MsgInMenu;
	while (true)//根据鼠标点击决定进入哪个页面
	{//有返回功能的界面 会在对应函数执行完后重新打印菜单界面
		if (peekmessage(&MsgInMenu, EM_MOUSE))//如果是鼠标点击
		{
			if (MsgInMenu.message == WM_LBUTTONDOWN)//且是左键点击
			{
				if (MsgInMenu.x >= WAITING && MsgInMenu.x <= WAITING && MsgInMenu.y >= WAITING && MsgInMenu.y <= WAITING)//1.点击开始游戏
				{
					ChoosePlane();
				}
				else if (MsgInMenu.x >= WAITING && MsgInMenu.x <= WAITING && MsgInMenu.y >= WAITING && MsgInMenu.y <= WAITING)//2.点击设置

				{
					SettingsView();//展示设置
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, L"", WAITING, WAITING);
					//设置标题
					settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(WAITING, WAITING, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(WAITING, WAITING, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
				}
				else if (MsgInMenu.x >= WAITING && MsgInMenu.x <= WAITING && MsgInMenu.y >= WAITING && MsgInMenu.y <= WAITING)//3.点击玩法介绍
				{
					Instructions();//展示玩法介绍
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, L"", WAITING, WAITING);
					//设置标题
					settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(WAITING, WAITING, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(WAITING, WAITING, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
				}
				else if (MsgInMenu.x >= WAITING && MsgInMenu.x <= WAITING && MsgInMenu.y >= WAITING && MsgInMenu.y <= WAITING)//4.点击团队介绍
				{
					PrintTeamIntroduction();//展示团队介绍
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, L"", WAITING, WAITING);
					//设置标题
					settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(WAITING, WAITING, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(WAITING, WAITING, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
					outtextxy(WAITING, WAITING, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
				}
				else if (MsgInMenu.x >= WAITING && MsgInMenu.x <= WAITING && MsgInMenu.y >= WAITING && MsgInMenu.y <= WAITING)//5.点击退出
				{
					break;
				}
			}

		}
	}
	closegraph();  // 关闭图形窗口
	exit(0);
}

void SettingsView() {
	cleardevice();
	//设置背景图（原型图并没有）
	IMAGE SettingsBackground;
	loadimage(&SettingsBackground, L"", WAITING, WAITING);
	setbkmode(TRANSPARENT);
	// 各设置按键
		//调整bgm
	settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(WAITING, WAITING, _T("BGM"));
	//展示编号
	wchar_t Bgm[5] = L"";
	wsprintf(Bgm, L"%d", AllGame::instance().bgm);
	settextstyle(WAITING, WAITING, L"");
	outtextxy(WAITING, WAITING, Bgm);
	//设置更改按键(加减号)
	IMAGE Plus;
	IMAGE Minus;
	loadimage(&Plus, L"", WAITING, WAITING);
	loadimage(&Minus, L"", WAITING, WAITING);
	//调整音量大小
	settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(WAITING, WAITING, _T("音量"));
	//展示当前音量大小
	wchar_t voice[5] = L"";
	wsprintf(voice, L"%d", AllGame::instance().vo);
	settextstyle(WAITING, WAITING, L"");
	outtextxy(WAITING, WAITING, voice);
	//设置更改按键(加减号)
	loadimage(&Plus, L"", WAITING, WAITING);
	loadimage(&Minus, L"", WAITING, WAITING);
	//调整音效大小
	settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(WAITING, WAITING, _T("音效"));
	//展示当前音效大小
	wchar_t sound_effect[5] = L"";
	wsprintf(sound_effect, L"%d", AllGame::instance().se);
	settextstyle(WAITING, WAITING, L"");
	outtextxy(WAITING, WAITING, sound_effect);
	//设置更改按键(加减号)
	loadimage(&Plus, L"", WAITING, WAITING);
	loadimage(&Minus, L"", WAITING, WAITING);
	//改变操作方式
	settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(WAITING, WAITING, _T("操作模式"));
	//展示当前音量大小
	wchar_t operate[10] = L"";
	wsprintf(operate, oper % 2 ? L"W/A/S/D" : L"鼠标");
	settextstyle(WAITING, WAITING, L"");
	outtextxy(WAITING, WAITING, operate);
	//设置更改按键(加减号)
	loadimage(&Plus, L"", WAITING, WAITING);
	loadimage(&Minus, L"", WAITING, WAITING);
	//设置返回键
	outtextxy(WAITING, WAITING, _T("返回"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(WAITING, WAITING, WAITING, WAITING);//位置待定
	ExMessage MsgInSettings;
	while (true)//根据鼠标点击决定进行什么操作
	{//有返回功能的界面 会在对应函数执行完后重新打印菜单界面
		if (peekmessage(&MsgInSettings, EM_MOUSE))//如果是鼠标点击
		{
			if (MsgInSettings.message == WM_LBUTTONDOWN)//且是左键点击
			{
				if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//1.1点击bgm-
				{
					AllGame::instance().bgm = max(1, --AllGame::instance().bgm);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//1.2点击bgm+
				{
					AllGame::instance().bgm = min(2, ++AllGame::instance().bgm);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//2.1点击vo-
				{
					AllGame::instance().vo = max(0, --AllGame::instance().vo);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//2.2点击vo-
				{
					AllGame::instance().vo = min(5, ++AllGame::instance().vo);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//3.1点击se-
				{
					AllGame::instance().se = max(0, --AllGame::instance().se);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//3.2点击se+
				{
					AllGame::instance().se = min(5, ++AllGame::instance().se);
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//4.1点击oper-
				{
					oper++;
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//3.2点击se+
				{
					oper++;
				}
				else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//3.2点击se+
				{
					break;
				}

			}
		}
	}
}
void PrintTeamIntroduction() {}//等原型

void Instructions() {}//等原型



int ChoosePlane() {








	return WAITING;

}/*该函数返回值决定 皮肤 MaxHp 射速等Player的性质
					实现战机选择 数值和立绘展示 以及战机选择
					-----即战备界面------*/

void PrintGameScene() {}//载入战机图片 bgm 和飞机的数值

void GameOverView() {}//展示得分

void GameView() {




	GameManager g;
	
	while ((*g.playerMgr.players[0]).NowHp > 0) {
			g.Update();
			g.Render();
			g.CG();

		}
		lock120fps();
	}
}