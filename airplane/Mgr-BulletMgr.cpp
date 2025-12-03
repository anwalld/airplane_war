#include "Behavior-PlaneBehavior.h"

#include "Behavior-BulletBehavior.h"
#include "Mgr-BulletMgr.h"
#include "system-system.h"
#include"Res-GameRes.h"
#include "core-bullet.h"
#include "core-Enemy.h"
#include "core-Player.h"
void BulletManager::AddBullet(bullet* b) {
	bullets.push_back(b);
}
void BulletManager::Produce(const std::vector<Player*>& p, const std::vector<Enemy*>& es) {
	for (Player* pp : p) {
		if (ShouldFire(pp)) {
			bullet* b = new bullet();
			if (pp->Vshoot != 1)b->app = 9;//玩家--直线ans斜线子弹
			else b->app=10;//玩家--激光子弹
			b->Type = (RandomInt(0, 99)<=90?0:1);//玩家子弹类型随机
			switch (b->Type) {
			case 0: { auto [vx, vy] = LineBullet(b); b->vx = vx; b->vy = vy; break; }
			case 1: { auto [vx, vy] = BiasBullet(b); b->vx = vx; b->vy = vy; break; }
			case 2: {
				auto [vx, vy] = TracedBullet(b, pp);
				b->vx = vx; b->vy = vy; break;
			}
			default:{ auto [vx, vy] = LineBullet(b); b->vx = vx; b->vy = vy; break; }
			}
			b->camp = 0;
			b->NowCoord = pp->coord;
			b->alive = true;
			b->ATK += pp->AddATK;
			AddBullet(b);
		}
	}
	for (Enemy* ee : es) {
		if (ShouldFire(ee)) {
			bullet* b = new bullet();
			auto [ATK, Type, Rad] = RandomAtkAndTypeAndRad(ee, b);
			b->ATK = ATK;
			b->Type = Type;
			b->rad = Rad;
			b->app = AppMatchEnemyType(ee,b);
			switch (b->Type) {
			case 0: { auto [vx, vy] = LineBullet(b); b->vx = vx; b->vy = vy; break; }
			case 1: { auto [vx, vy] = BiasBullet(b); b->vx = vx; b->vy = vy; break; }
			case 2: 
				auto [vx, vy] = TracedBullet(b, p[0]);
				b->vx = vx; b->vy = vy; break;
			}
			b->camp = 1;
			b->NowCoord = ee->coord;
			b->alive = true;
			AddBullet(b);
		}
	}
}
void BulletManager::Update(const std::vector<Player*>& p, const std::vector<Enemy*>& es) {
	//2.生成子弹
	Produce(p,es);

	//3. 移动子弹
	for (bullet* b : bullets) {		
		if (IsOutRange(b->NowCoord)) {
			b->alive = false;
		}
		if (b->alive == false) continue;
		b->NowCoord = CalcuBulletMove(b,p[0]);
	}

	//4. 碰撞检测
	for (bullet* b : bullets) {
		if (b->alive == false) continue;
		if (b->camp == 0) {
			// 玩家子弹 → 打敌机
			for (Enemy* e : es) {
				if (!IsSameCamp(e->camp, b->camp) && IsCrash(b->NowCoord, b->rad, e->coord, e->rad)) {
					e->NowHp -= b->ATK;
					b->alive = false;
				}
			}
		}
		else {
			// 敌机子弹 → 打玩家
			for (Player* pp : p) {
				if (!IsSameCamp(pp->camp, b->camp) && IsCrash(b->NowCoord, b->rad, pp->coord, pp->rad)) {
					pp->NowHp -= b->ATK;
					b->alive = false;
				}
			}
		}
	}


}
void BulletManager::Render() {
	Resourse res;

	for (const bullet* b : bullets) {
		int idx = b->app;
		if (idx < 0 || idx >= res.bulletImgs.size())
			continue;

		// 子弹可视尺寸 = 判定圆直径
		int w = b->rad * 2;
		int h = b->rad * 2;

		// 中心点坐标 → 左上角
		int x = (int)(b->NowCoord.first - b->rad);
		int y = (int)(b->NowCoord.second - b->rad);

		drawAlphaResize(x, y, w, h, &res.bulletImgs[idx]);
	}
}


void BulletManager::GC() {
	//easyx




	//kill
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(),
			[](bullet* b) {
				if (!b->alive) {
					AllKindDestroy(b);
					return true;
				}
				else return false;
			}),
		bullets.end()
	);
}