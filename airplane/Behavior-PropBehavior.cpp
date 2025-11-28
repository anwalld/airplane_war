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

	// 左右范围：[rad, screenX - rad]
	double x = RandomDouble(p->rad, screenX - p->rad);
	// 上 1/4 的高度：范围 [rad, screenY/4 - rad]
	double topQuarter = 1.0*screenY / 4;
	double y = RandomDouble(p->rad,topQuarter-p->rad);
	p->NowCoord = { x, y };
	return p->NowCoord;
}
//落叶移动
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
	CurVx[p] += (TarVx[p] - CurVx[p]) * 0.2;
	p->vx = p->speed * CurVx[p];
	p->vy = 2;
	return { p->vx,p->vy };
}
std::pair<double, double>PropMoveCoord(prop* p) {
	std::pair<double, double>v = LeaveMoveVxAndVy(p);
	p->NowCoord = SystemMove(p->NowCoord,v.first,v.second);
	return p->NowCoord;
}
//道具的具体功能实现
//0--永久加属性类
//0.0减小飞机vShoot
void PropEffect_DecreaseVShoot(Player* player, prop* p);
//0.1增加子弹伤害
void PropEffect_IncreaseBulletDamage(Player* player, prop* p);
//0.2增加子弹攻击力
void PropEffect_IncreaseBulletAtk(Player* player, prop* p);
//0.3增加飞机MaxHp
void PropEffect_IncreasePlaneMaxHp(Player* player, prop* p);
//0.4增加飞机speed
void PropEffect_IncreasePlaneSpeed(Player* player, prop* p);
//1--一次性道具类
//1.0回血
void PropEffect_Heal(Player* player, prop* p);
//1.1清屏
void PropEffect_ClearScreen(std::vector<bullet*>& bullets, std::vector<Enemy*>& enemies, prop* p);
//1.2无敌(更改身份识别)
void PropEffect_Invincible(Player* player, prop* p);
//1.3全屏炸弹
void PropEffect_FullScreenBomb(std::vector<Enemy*>& enemies,prop* p);
//2--限时类
//2.0激光武器
void PropEffect_LaserWeapon(Player* player, prop* p);
//2.1超级子弹
void PropEffect_SuperBullet(Player* player, prop* p);
//2.2难度暂时降低
void PropEffect_DecreaseDif(prop* p);