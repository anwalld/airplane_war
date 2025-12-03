#include"system-view.h"
#include "easyx.h"
#include"graphics.h"
#include"system-engine.h"
#include"Mgr-GameMgr.h"
#include"system-system.h"
#include<tchar.h>
int WAITING = 100;//等待尺寸数值
int oper = 0;



void MenuView() {
	//新建窗口	
	initgraph(1920, 1080);
	setbkcolor(WHITE);
	cleardevice();
	//设置背景图
	IMAGE MenuBackground;
	loadimage(&MenuBackground, "image\\ui\\bgp.png", 1920, 1080);
	putimage(0, 0, &MenuBackground);
//设置标题
settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
settextcolor(BLACK);//不一定是黑色
outtextxy(625, 60, _T("WARLIGHTING"));
outtextxy(830, 280, _T("开始游戏"));
//setfillcolor(0x000000);//颜色待定
//fillrectangle(830, 280, 1090, 360);//位置待定
outtextxy(830, 430, _T("游戏设置"));
//setfillcolor(0x000000);//颜色待定
//fillrectangle(830, 280, 1090, 510);//位置待定
outtextxy(830, 580, _T("玩法说明"));
//setfillcolor(0x000000);//颜色待定
//fillrectangle(830, 580, 1090, 660);//位置待定
outtextxy(830, 730, _T("团队介绍"));
//setfillcolor(0x000000);//颜色待定
//fillrectangle(830, 730, 1090, 810);//位置待定
outtextxy(830, 880, _T("退出游戏"));
//setfillcolor(0x000000);//颜色待定
//fillrectangle(830, 880, 1090, 960);//位置待定
	ExMessage MsgInMenu;
	while (true)//根据鼠标点击决定进入哪个页面
	{//有返回功能的界面 会在对应函数执行完后重新打印菜单界面
		if (peekmessage(&MsgInMenu, EM_MOUSE))//如果是鼠标点击
		{
			if (MsgInMenu.message == WM_LBUTTONDOWN)//且是左键点击
			{
				if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 280 && MsgInMenu.y <= 360)//1.点击开始游戏
				{
					// 进入战机选择后，退出菜单函数，回到 GameView 继续执行游戏循环
					ChoosePlane();
					return;
				}
				else if (MsgInMenu.x >= 830 && MsgInMenu.x <= 1090 && MsgInMenu.y >= 430 && MsgInMenu.y <= 510)//2.点击设置

				{
					SettingsView();//展示设置
					cleardevice();
					//设置背景图
					IMAGE MenuBackground;
					loadimage(&MenuBackground, "image\\ui\\bgp.png", 1920, 1080);
					putimage(0, 0, &MenuBackground);
					//设置标题
					settextstyle(80, 0, _T("黑体"));//字体不一定是黑体
					settextcolor(BLACK);//不一定是黑色
					outtextxy(625, 60, _T("\nWAR LIGHTING"));
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
					loadimage(&MenuBackground, "image\\ui\\bgp.png", 1920, 1080);
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
					loadimage(&MenuBackground, "image\\ui\\bgp.png", 1920, 1080);
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

}

void SettingsView() {
	cleardevice();
	//设置背景图（原型图并没有）
	IMAGE SettingsBackground;
	loadimage(&SettingsBackground, "image\\ui\\bgp.png", 1920, 1080);
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
	loadimage(&Plus, "image\\ui\\plus.png", 80, 80);
	loadimage(&Minus, "image\\ui\\minus,png", 80, 80);
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
    settextstyle(36, 0, _T("微软雅黑"));

    // ===== 背景图 =====
    IMAGE bg;
    loadimage(&bg, "image\\ui\\bgp.png");

    // ===== 加载四张飞机贴图 =====
    IMAGE PlaneImg[4];
    for (int i = 0; i < 4; i++) {
        char path[64];
        sprintf(path, "image\\player\\%d.png", i);
        loadimage(&PlaneImg[i], path);
    }

    cleardevice();

    // ===== 布局区域 =====
    int bigX = 320, bigY = 80, bigW = 640, bigH = 640;
    int attrX1 = 1000, attrY1 = 80, attrX2 = 1300, attrY2 = 720;

    int iconW = 200, iconH = 200, iconY = 760;
    int bx[4] = { 320, 540, 760, 980 };

    TCHAR buff[64];

    // ===== 刷新界面函数 =====
    auto RefreshUI = [&](int idx) {
        cleardevice();
        putimage(0, 0, &bg);

        // ===== 左侧大图展示 =====
        setfillcolor(RGB(20,20,20));
        fillrectangle(bigX, bigY, bigX + bigW, bigY + bigH);
        rectangle(bigX, bigY, bigX + bigW, bigY + bigH);

        drawAlphaResize(bigX, bigY, bigW, bigH, &PlaneImg[idx]);

        // ===== 属性框 =====
        setfillcolor(RGB(30,30,30));
        fillrectangle(attrX1, attrY1, attrX2, attrY2);
        rectangle(attrX1, attrY1, attrX2, attrY2);

        auto [hp, atk, speed] = PlaneInitDataShow::planeAttr[idx];

        _stprintf(buff, _T("血量：%d"), hp);
        outtextxy(attrX1 + 20, attrY1 + 120, buff);

        _stprintf(buff, _T("攻击力：%d"), atk);
        outtextxy(attrX1 + 20, attrY1 + 180, buff);

        _stprintf(buff, _T("速度：%.2f"), speed);
        outtextxy(attrX1 + 20, attrY1 + 240, buff);

        // ===== 底部四个按钮小图 =====
        for (int i = 0; i < 4; i++) {
            if (i == idx) {
                setlinecolor(RGB(255,215,0));
                setlinestyle(PS_SOLID, 5);
            } else {
                setlinecolor(WHITE);
                setlinestyle(PS_SOLID, 1);
            }

            rectangle(bx[i], iconY, bx[i] + iconW, iconY + iconH);
            drawAlphaResize(bx[i] + 10, iconY + 10, iconW - 20, iconH - 20, &PlaneImg[i]);
        }

        // ===== 出击按钮 =====
        setfillcolor(RGB(40,40,40));
        fillrectangle(1500, 760, 1700, 900);
        rectangle(1500, 760, 1700, 900);
        outtextxy(1550, 810, _T("出击"));
    };

    // ===== 初次刷新 =====
    RefreshUI(PlaneIndex);

    // ===== 输入循环 =====
    ExMessage m;
    while (true) {
        if (peekmessage(&m, EM_MOUSE) && m.message == WM_LBUTTONDOWN) {
            
            // 选择飞机按钮
            for (int i = 0; i < 4; i++) {
                if (m.x >= bx[i] && m.x <= bx[i] + iconW &&
                    m.y >= iconY && m.y <= iconY + iconH) {

                    PlaneIndex = i;
                    RefreshUI(PlaneIndex);
                }
            }

            // 出击按钮
            if (m.x >= 1500 && m.x <= 1700 &&
                m.y >= 760  && m.y <= 900) {
                break;
            }
        }
    }

    AllGame::instance().skin = PlaneIndex;
    return PlaneIndex;
}

/*该函数返回值决定 皮肤 MaxHp 射速等Player的性质
					实现战机选择 数值和立绘展示 以及战机选择
					-----即战备界面------*/

void PrintGameScene(const GameManager& g) {
	/*IMAGE GameBackGround;
	loadimage(&GameBackGround, "", 1920, 1080);
	putimage(0, 0, &GameBackGround);*/
	int NowHp = g.playerMgr.players[0]->NowHp;
	setfillcolor(0x4f07db);
	fillrectangle(0, 530, 480 * (NowHp) / 100, 570);


}//载入战机图片 bgm 和飞机的数值

void GameOverView() {}//展示得分

void GameView() {
	// 先走菜单（里面已经 initgraph 过了）
	MenuView();

	// 双缓冲缓冲区，必须指定大小
	IMAGE buf(1920, 1080);

	GameManager g;

	while (g.playerMgr.players[0]->NowHp > 0) {
		// 每帧更新游戏时间与难度系数
		AllGame::instance().ChangeGameTime();
		AllGame::instance().coef = AllGame::instance().CalculateCoef();

		// 所有绘制都画到 buf 上
		SetWorkingImage(&buf);
		cleardevice();          // 清空 buf

		g.Update();
		g.Render();
		g.CG();
		PrintGameScene(g);
		// 把 buf 一次性贴到屏幕
		SetWorkingImage(NULL);  // 切回屏幕
		putimage(0, 0, &buf);

		// 锁 120 帧
		lock120fps();
	}


}
