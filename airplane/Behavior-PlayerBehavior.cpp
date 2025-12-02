#include "behavior-PlayerBehavior.h"
#include "system-engine.h"
#include "easyx.h"
#include "graphics.h"
//根据皮肤更改玩家参数  0--高血量 1--高攻击 2--高速度 3--均衡  tuple--0:maxHp 1:AddATK 2:speed
std::tuple<int,int,double> ChangePlayerParam(Player* p) {
    switch (p->skin) {
    case 0: {
        p->maxHp += 50;
        break;
    }
    case 1: {
        p->AddATK += 5;
        break;
    }
    case 2: {
        p->speed += 1.0 * 50 / 120;
        break;
    }
    case 3: {
        p->maxHp += 20;
        p->AddATK += 2;
        p->speed += 1.0 * 20 / 120;
        break;
    }
    default:
		break;
    }
	return { p->maxHp, p->AddATK,p->speed };
}

std::pair<double, double>ProducePlayer(Player* p) {
	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// x = 屏幕中点
    double x = screenX / 2.0;

	// y = 屏幕底部往上 1/8
    double y = (screenY * 7) / 8.0;

	return { x,y };
}
std::pair<double, double> GetPlayerCoord(Player* p)
{
    ExMessage msg{};

    // 使用单次 peekmessage 检查鼠标和键盘事件，避免重复调用 peekmessage
    while (peekmessage(&msg, EX_MOUSE | EX_KEY)) 
    {
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
            p->coord.second = nowY;
        }       

        if (msg.message == WM_KEYDOWN && msg.vkcode == VK_ESCAPE)
        {
            AllGame::instance().Stop = true;
        }
    }

    return p->coord;
}
