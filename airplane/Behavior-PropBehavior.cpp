#include "system-system.h"
#include<random>
#include"Behavior-PropBehavior.h"
#include"system-engine.h"
#include<unordered_map>
#include"core-Player.h"
std::pair<int, int> RandomTypeAndNum(Player* player,prop*p)
{
    double diff = AllGame::instance().coef;  // 难度(0~1)

    double hpRatio = (double)player->NowHp / player->maxHp;
    double HP_factor = 1 + (1 - hpRatio) * 2;     // 1~3，血越少越高

    double Permanent_factor = 1 - 0.5 * diff;   // 难度越高 永久类越少
    double Speed_factor = 1 + diff * 1.0;   // 难度越高 SpeedUp 越多
    double DecreaseDif_factor = 1 - 0.7 * diff;   // 难度越高 降低难度越少
    double Nerf_factor = 1 - 0.4 * diff;   // 清屏/炸弹/无敌减少

    // ===== 0 永久类 =====
    double w_shoot = 6 * Permanent_factor;
    double w_damage = 5 * Permanent_factor;
    double w_maxhp = 5 * Permanent_factor;
    double w_speed = 4 * Speed_factor;

    // ===== 1 一次性类 =====
    double w_heal = 12 * HP_factor;
    double w_clear = 15 * Nerf_factor;
    double w_bomb = 18 * Nerf_factor;

    // ===== 2 限时类 =====
    double w_laser = 8;
    double w_super = 12;
    double w_decreaseDif = 5 * HP_factor * DecreaseDif_factor;
    double w_invincible = 10 * HP_factor * Nerf_factor;

    // ===== 权重数组 + 映射 =====
    std::vector<double> all;
    std::vector<std::pair<int, int>> mapping;

    auto append = [&](const std::vector<double>& v, int big) {
        for (int i = 0; i < v.size(); i++) {
            all.push_back(v[i]);
            mapping.push_back({ big, i });
        }
        };

    // 0 永久类（4个）
    append({ w_shoot, w_damage, w_maxhp, w_speed }, 0);

    // 1 一次性类（3个）
    append({ w_heal, w_clear, w_bomb }, 1);

    // 2 限时类（4个）
    append({ w_laser, w_super, w_decreaseDif, w_invincible }, 2);

    // ===== 求总权重 =====
    double total = 0;
    for (double w : all) total += w;

    double r = RandomDouble(0, total);  

    std::pair<int, int>TypeAndNum = { 0,0 };
    // ===== 按区间抽取 =====
    for (int i = 0; i < all.size(); i++) {
        if (r < all[i]) {
            TypeAndNum = mapping[i]; break;
        }
        r -= all[i];
    }
	p->type = TypeAndNum.first;
	p->num = TypeAndNum.second;
	return TypeAndNum;
}
//根据道具类型和编号对应app
int AppMatchProp(prop* p) {
    switch (p->type) {
    case 0: { // 永久类
        switch (p->num) {
        case 0: p->app = 0; break; // 减小vShoot
        case 1: p->app = 1; break; // 增加子弹伤害
        case 2: p->app = 2; break; // 增加MaxHp
        case 3: p->app = 3; break; // 增加speed
        }
        break;
    }
    case 1: { // 一次性类
        switch (p->num) {
        case 0: p->app = 4; break; // 回血
        case 1: p->app = 5; break; // 清屏
        case 2: p->app = 6; break; // 全屏炸弹
        }
        break;
    case 2: { // 限时类
        switch (p->num) {
        case 0: p->app = 7; break; // 激光武器
        case 1: p->app = 8; break; // 超级子弹
        case 2: p->app = 9; break; // 减少难度
        case 3: p->app = 10; break; // 无敌
        }
        break;
    }
    default: p->app = 0; break;
    }
    }
	return p->app;
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
void PropEffect_DecreaseVShoot(Player* player, prop* p) {
    if (player->Vshoot > 1) {
        player->Vshoot -= 1;
	}
    p->CD = 1.0 * 1000 / 120-1;
	p->alive = false;
}
//0.1增加子弹伤害
void PropEffect_IncreaseBulletDamage(Player* player, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
	player->AddATK += 5;
	p->alive = false;
}
//0.2增加飞机MaxHp
void PropEffect_IncreasePlaneMaxHp(Player* player, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
    player->maxHp += 20;
	p->alive = false;
}
//0.3增加飞机speed
void PropEffect_IncreasePlaneSpeed(Player* player, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
	player->speed += 0.2 * 200 / 120;
	p->alive = false;
}
//1--一次性道具类
//1.0回血
void PropEffect_Heal(Player* player, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
	player->NowHp += 10;
	p->alive = false;
}
//1.1清屏
void PropEffect_ClearScreen(BulletManager& b, EnemyManager& e, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
    for(auto& bullet : b.bullets) {
        if(bullet->camp != p->camp) {
            bullet->alive = false;
        }
	}
    for(auto& enemy : e.enemies) {
        if(enemy->camp != p->camp) {
            enemy->alive = false;
        }
	}
	p->alive = false;
}
//1.2全屏炸弹(爆炸cg)
void PropEffect_FullScreenBomb(EnemyManager& e, prop* p) {
    p->CD = 1.0 * 1000 / 120 - 1;
    for(auto& enemy : e.enemies) {
        if(enemy->camp != p->camp) {
            enemy->NowHp -= 50;
        }
    }
	p->alive = false;
}
//2--限时类
//2.0激光武器
void PropEffect_LaserWeapon(Player* player, prop* p) {
    player->Vshoot  = 1;
    player->AddATK -= 5;
}
//2.1超级子弹
void PropEffect_SuperBullet(Player* player, prop* p) {
	player->atk += 20;
}
//2.2临时减少杀敌数(降低难度)
void PropEffect_DecreaseDif(prop* p) {
	AllGame::instance().AllKill = (AllGame::instance().AllKill >= 100) ? AllGame::instance().AllKill - 100 : 0;
}
//2.3无敌(更改身份识别)(要求生成概率不高于10%)
void PropEffect_Invincible(Player* player, prop* p) {
    player->camp = 1;
}