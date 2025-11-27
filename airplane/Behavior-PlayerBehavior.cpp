#include "behavior-PlayerBehavior.h"
#include "system-engine.h"
#include"easyx.h"
#include"graphics.h"
std::pair<double, double>ProducePlayer(Player* p) {
	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// x = 屏幕中点
    double x = screenX / 2;

	// y = 屏幕底部往上 1/8
    double y = (screenY * 7) / 8;

	return { x,y };
}
std::pair<double, double> GetPlayerCoord(Player* p) {
    ExMessage msg;
    // 同时监听鼠标 + 键盘
    while (peekmessage(&msg, EM_MOUSE | EM_KEY))
    {
        // 鼠标移动：更新玩家坐标
        if (msg.message == WM_MOUSEMOVE)
        {
            double targetX = msg.x;
            double targetY = msg.y;

            const double smooth = 0.2;

            double nowX = p->coord.first;
            double nowY = p->coord.second;

            nowX += (targetX - nowX) * smooth;
            nowY += (targetY - nowY) * smooth;

            p->coord.first = nowX;
            p->coord.second =nowY;
        }

        // 监听 ESC（键盘）
        if (msg.message == WM_KEYDOWN && msg.vkcode == VK_ESCAPE)
        {
             AllGame::instance().Stop = true;
        }
    }

    return p->coord;
}