#include "behavior-PlayerBehavior.h"
#include "system-engine.h"
#include"easyx.h"
#include"graphics.h"
std::pair<int, int>ProducePlayer(Player* p) {
	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// x = 屏幕中点
	int x = screenX / 2;

	// y = 屏幕底部往上 1/8
	int y = (screenY * 7) / 8;

	return { x,y };
}
std::pair<int, int>GetPlayerCoord(Player* p) {
    ExMessage msg;
    while (peekmessage(&msg, EM_MOUSE))
    {
        if (msg.message == WM_MOUSEMOVE)
        {
            // 目标坐标为鼠标坐标
            float targetX = msg.x;
            float targetY = msg.y;

            // 平滑比例（越小越丝滑，越大越跟手）
            const float smooth = 0.20f;  // 20% 插值

            // 当前坐标
            float nowX = p->coord.first;
            float nowY = p->coord.second;

            // 插值计算（线性插值）
            nowX += (targetX - nowX) * smooth;
            nowY += (targetY - nowY) * smooth;

            // 写回玩家坐标
            p->coord.first = (int)nowX;
            p->coord.second = (int)nowY;
        }
    }
    return p->coord;
}