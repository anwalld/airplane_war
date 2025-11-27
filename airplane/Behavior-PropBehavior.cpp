#include "system-system.h"
#include<random>
#include"Behavior-PropBehavior.h"
#include"system-engine.h"
#include<unordered_map>
int RandomType(prop* p) {
	return RandomInt(0,2);
}

std::pair<double, double>RandomProduceCoord(prop* p) {
	int screenX = AllGame::instance().ScreenX;
	int screenY = AllGame::instance().ScreenY;

	// ×óÓÒ·¶Î§£º[rad, screenX - rad]
	double x = RandomDouble(p->rad, screenX - p->rad);
	// ÉÏ 1/4 µÄ¸ß¶È£º·¶Î§ [rad, screenY/4 - rad]
	double topQuarter = 1.0*screenY / 4;
	double y = RandomDouble(p->rad,topQuarter-p->rad);
	p->NowCoord = { x, y };
	return p->NowCoord;
}
//ÂäÒ¶ÒÆ¶¯
static std::unordered_map<prop*, double>CurVx;
static std::unordered_map<prop*, double>TarVx;
std::pair<double, double>LeaveMoveVxAndVy(prop* p) {
	if (CurVx.find(p) == CurVx.end()) {
		CurVx[p] = 0;
		TarVx[p] = 1;
	}
	if (RandomDouble(0, 1) <= 0.3) {
		TarVx[p] = RandomDouble(-1, 1);
	}
	if (p->NowCoord.first - p->rad <= 0) {
		CurVx[p] = std::fabs(CurVx[p]);
		TarVx[p] = std::fabs(TarVx[p]);
	}
	else if (p->NowCoord.first + p->rad >= AllGame::instance().ScreenX) {
		CurVx[p] = -std::fabs(CurVx[p]);
		TarVx[p] = -std::fabs(TarVx[p]);
	}
	CurVx[p] = (TarVx[p] - CurVx[p]) * 0.2;
	p->vx = p->speed * CurVx[p];
	p->vy = 2;
	return { p->vx,p->vy };
}
std::pair<double, double>PropMoveCoord(prop* p) {
	std::pair<double, double>v = LeaveMoveVxAndVy(p);
	p->NowCoord = SystemMove(p->NowCoord,v.first,v.second);
	return p->NowCoord;
}