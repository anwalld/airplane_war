#include"system-view.h"
#include "easyx.h"
#include"graphics.h"
#include"system-engine.h"
#include"Mgr-GameMgr.h"
#include"system-system.h"
int WAITING = 100;//等待尺寸数值
int oper = 0;

void MenuView() {
	//新建窗口	
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();
	//设置背景图
	IMAGE MenuBackground;
	loadimage(&MenuBackground, "", 1920, 1080);
	putimage(0, 0, &MenuBackground);
	//设置标题
	settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(625, 60, _T("\nWAR LIGHTING"));
	//设置选项
	outtextxy(50, 0, _T("开始游戏"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 280, 1090, 360);//位置待定
	outtextxy(830, 280, _T("游戏设置"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 280, 1090, 510);//位置待定
	outtextxy(830, 430, _T("玩法说明"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 580, 1090, 660);//位置待定
	outtextxy(830, 580, _T("团队介绍"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 730, 1090, 810);//位置待定
	outtextxy(830, 730, _T("退出游戏"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 880, 1090, 960);//位置待定
	ExMessage MsgInMenu;
	while (true)//根据鼠标点击决定进入哪个页面
	{//有返回功能的界面 会在对应函数执行完后重新打印菜单界面
		if (peekmessage(&MsgInMenu, EM_MOUSE))//如果是鼠标点击
		{
			if (MsgInMenu.message == WM_LBUTTONDOWN)//且是左键点击
			{
				if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 280 && MsgInMenu.y <= 360)//1.点击开始游戏
				{
					ChoosePlane();
				}
				else if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 430 && MsgInMenu.y <= 510)//2.点击设置

				{
					SettingsView();//展示设置
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, "", 1920, 1080);
					putimage(0, 0, &MenuBackground);
					//设置标题
					settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(625, 60, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(50, 0, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 360);//位置待定
					outtextxy(830, 280, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 510);//位置待定
					outtextxy(830, 430, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 580, 1090, 660);//位置待定
					outtextxy(830, 580, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 730, 1090, 810);//位置待定
					outtextxy(830, 730, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 880, 1090, 960);//位置待定
				}
				else if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 580 && MsgInMenu.y <= 660)//3.点击玩法介绍
				{
					Instructions();//展示玩法介绍
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, "", 1920, 1080);
					putimage(0, 0, &MenuBackground);
					//设置标题
					settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(625, 60, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(50, 0, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 360);//位置待定
					outtextxy(830, 280, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 510);//位置待定
					outtextxy(830, 430, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 580, 1090, 660);//位置待定
					outtextxy(830, 580, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 730, 1090, 810);//位置待定
					outtextxy(830, 730, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 880, 1090, 960);//位置待定
				}
				else if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 730 && MsgInMenu.y <= 810)//4.点击团队介绍
				{
					PrintTeamIntroduction();//展示团队介绍
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, "", 1920, 1080);
					putimage(0, 0, &MenuBackground);
					//设置标题
					settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(625, 60, _T("\nWAR LIGHTING"));
					//设置选项
					outtextxy(50, 0, _T("开始游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 360);//位置待定
					outtextxy(830, 280, _T("游戏设置"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 280, 1090, 510);//位置待定
					outtextxy(830, 430, _T("玩法说明"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 580, 1090, 660);//位置待定
					outtextxy(830, 580, _T("团队介绍"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 730, 1090, 810);//位置待定
					outtextxy(830, 730, _T("退出游戏"));
					setfillcolor(0x000000);//颜色待定
					fillrectangle(830, 880, 1090, 960);//位置待定
				}
				else if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 880 && MsgInMenu.y <= 960)//5.点击退出
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
	loadimage(&SettingsBackground, "", 1920, 1080);
	putimage(0, 0, &SettingsBackground);
	setbkmode(TRANSPARENT);
	// 各设置按键
		//调整bgm
	settextstyle(30, 30, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(120, 120, _T("BGM"));
	//展示编号
	settextstyle(20, 20, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(1640, 140, _T("%d", AllGame::instance().bgm));
	//设置更改按键(加减号)
	IMAGE Plus;
	IMAGE Minus;
	loadimage(&Plus, "", 80, 80);
	loadimage(&Minus, "", 80, 80);
	putimage(1580, 160, &Minus);
	putimage(1740, 160, &Plus);
	//调整音量大小
	settextstyle(30, 30, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(120, 280, _T("音量"));
	//展示当前音量大小
	settextstyle(20, 20, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(1640, 300, _T("%d", AllGame::instance().vo));
	//设置更改按键(加减号)
	putimage(1580, 320, &Minus);
	putimage(1740, 320, &Plus);
	//调整音效大小
	settextstyle(30, 30, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(120, 440, _T("音效"));
	//展示当前音效大小
	settextstyle(20, 20, _T("黑体"));//字体不一定是黑体
	settextcolor(BLACK);//不一定是黑色
	outtextxy(1640, 460, _T("%d", AllGame::instance().se));
	//设置更改按键(加减号)
	putimage(1580, 480, &Minus);
	putimage(1740, 480, &Plus);
	////改变操作方式
	//settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	//settextcolor(BLACK);//不一定是黑色
	//outtextxy(WAITING, WAITING, _T("操作模式"));
	////展示当前音量大小
	//settextstyle(WAITING, WAITING, _T("黑体"));//字体不一定是黑体
	//settextcolor(BLACK);//不一定是黑色
	//outtextxy(WAITING, WAITING, _T(oper % 2 ? "W / A / S / D" : "鼠标"));

	////设置更改按键(加减号)
	//loadimage(&Plus, "", WAITING, WAITING);
	//loadimage(&Minus, "", WAITING, WAITING);
	//设置返回键
	outtextxy(830, 680, _T("返回"));
	setfillcolor(0x000000);//颜色待定
	fillrectangle(830, 680, 1090, 760);//位置待定
	ExMessage MsgInSettings;
	while (true)//根据鼠标点击决定进行什么操作
	{//有返回功能的界面 会在对应函数执行完后重新打印菜单界面
		if (peekmessage(&MsgInSettings, EM_MOUSE))//如果是鼠标点击
		{
			if (MsgInSettings.message == WM_LBUTTONDOWN)//且是左键点击
			{
				if (MsgInSettings.x >= 1580 && MsgInSettings.x <= 1620 && MsgInSettings.y >= 160 && MsgInSettings.y <= 200)//1.1点击bgm-
				{
					AllGame::instance().bgm = max(1, --AllGame::instance().bgm);
				}
				else if (MsgInSettings.x >= 1740 && MsgInSettings.x <= 1780 && MsgInSettings.y >= 160 && MsgInSettings.y <= 200)//1.2点击bgm+
				{
					AllGame::instance().bgm = min(2, ++AllGame::instance().bgm);
				}
				else if (MsgInSettings.x >= 1580 && MsgInSettings.x <= 1620 && MsgInSettings.y >= 320 && MsgInSettings.y <= 360)//2.1点击vo-
				{
					AllGame::instance().vo = max(0, --AllGame::instance().vo);
				}
				else if (MsgInSettings.x >= 1740 && MsgInSettings.x <= 1780 && MsgInSettings.y >= 320 && MsgInSettings.y <= 360)//2.2点击vo-
				{
					AllGame::instance().vo = min(5, ++AllGame::instance().vo);
				}
				else if (MsgInSettings.x >= 1580 && MsgInSettings.x <= 1620 && MsgInSettings.y >= 480 && MsgInSettings.y <= 520)//3.1点击se-
				{
					AllGame::instance().se = max(0, --AllGame::instance().se);
				}
				else if (MsgInSettings.x >= 1740 && MsgInSettings.x <= 1780 && MsgInSettings.y >= 480 && MsgInSettings.y <= 520)//3.2点击se+
				{
					AllGame::instance().se = min(5, ++AllGame::instance().se);
				}
				//else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//4.1点击oper-
				//{
				//	oper++;
				//}
				//else if (MsgInSettings.x >= WAITING && MsgInSettings.x <= WAITING && MsgInSettings.y >= WAITING && MsgInSettings.y <= WAITING)//3.2点击se+
				//{
				//	oper++;
				//}
				else if (MsgInSettings.x >= 830 && MsgInSettings.x <= 1090 && MsgInSettings.y >= 680 && MsgInSettings.y <= 760)//3.2点击se+
				{
					break;
				}

			}
		}
	}
}
void PrintTeamIntroduction() {
	IMAGE ChooseBackground;
	loadimage(&ChooseBackground, "", 1920, 1080);
	putimage(0, 0, &ChooseBackground);








}//等原型

void Instructions() {}//等原型



int ChoosePlane() {
	int PlaneIndex = 0;
	settextstyle(36, 0, _T("微软雅黑"));//字体大小和样式

	IMAGE Plane0;
	loadimage(&Plane0, "", 640, 640);
	IMAGE Plane1;
	loadimage(&Plane1, "", 640, 640);
	IMAGE Plane2;
	loadimage(&Plane2, "", 640, 640);




	setfillcolor(0x000000);
	fillrectangle(320, 80, 800, 720);  // 左上角(320,80)，右下角(800,720)（尺寸640*640）
	rectangle(320, 80, 800, 720);      // 绘制边框
	outtextxy(480, 380, _T("立绘贴图")); // 文字居中显示


	setfillcolor(0x000000);
	fillrectangle(800, 80, 1120, 720); // 左上角(800,80)，右下角(1120,720)（尺寸320*640）
	rectangle(800, 80, 1120, 720);
	outtextxy(920, 380, _T("血量：%d", PlayerPlaneData(PlaneIndex).first));
	outtextxy(920, 400, _T("射速：%d", PlayerPlaneData(PlaneIndex).second));
	outtextxy(920, 420, _T("攻击力：%d", PlayerPlaneData(PlaneIndex).third));

	// ========== 3. 绘制“种类1”模块 ==========
	loadimage(&Plane0, "", 320, 200);
	putimage(320, 720, &Plane0);


	// ========== 4. 绘制“种类2”模块 ==========
	loadimage(&Plane1, "", 320, 200);
	putimage(640, 720, &Plane1);


	// ========== 5. 绘制“种类3”模块 ==========
	loadimage(&Plane2, "", 320, 200);
	putimage(800, 720, &Plane2);


	// ========== 6. 绘制“返回”模块 ==========
	//setfillcolor(0x000000);
	//fillrectangle(80, 720, 280, 920);   // 左上角(80,720)，右下角(280,920)（尺寸200*200）
	//rectangle(80, 720, 280, 920);
	//outtextxy(130, 800, _T("返回"));

	// ========== 7. 绘制“出击”模块 ==========
	setfillcolor(0x000000);
	fillrectangle(1640, 720, 1840, 920); // 左上角(1640,720)，右下角(1840,920)（尺寸200*200）
	rectangle(1640, 720, 1840, 920);
	outtextxy(1690, 800, _T("出击"));

	ExMessage ChoosePlane;
	while (true) {
		if (peekmessage(&ChoosePlane, EM_MOUSE)) {
			if (ChoosePlane.message == WM_LBUTTONDOWN) {
				if (ChoosePlane.x >= 480 && ChoosePlane.x <= 800 && ChoosePlane.y >= 720 && ChoosePlane.y <= 920) {
					PlaneIndex = 0;
				}
				else if (ChoosePlane.x >= 800 && ChoosePlane.x <= 1120 && ChoosePlane.y >= 720 && ChoosePlane.y <= 920) {
					PlaneIndex = 1;
				}
				else if (ChoosePlane.x >= 1120 && ChoosePlane.x <= 1440 && ChoosePlane.y >= 720 && ChoosePlane.y <= 920) {
					PlaneIndex = 2;

				}
				/*else if (ChoosePlane.x >=80 && ChoosePlane.x <=280 && ChoosePlane.y >=720 && ChoosePlane.y <=1000 ) {

				}*/
				else if (ChoosePlane.x >= 1640 && ChoosePlane.x <= 1840 && ChoosePlane.y >= 720 && ChoosePlane.y <= 1000) {
					break;
				}


			}

		}






	}





	return PlaneIndex;

}/*该函数返回值决定 皮肤 MaxHp 射速等Player的性质
					实现战机选择 数值和立绘展示 以及战机选择
					-----即战备界面------*/

void PrintGameScene() {}//载入战机图片 bgm 和飞机的数值

void GameOverView() {}//展示得分

void GameView() {




	GameManager g;
	while (g.playerMgr.players[0]->NowHp > 0) {
		g.Update();
		g.Render();
		g.CG();
		lock120fps();
	}
	
}
