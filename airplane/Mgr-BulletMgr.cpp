#include "Behavior-PlaneBehavior.h"

#include "Behavior-BulletBehavior.h"

#include "Mgr-BulletMgr.h"
#include "system-system.h"

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
			b->app = AppMatchEnemyType(b);
			b->Type = RandomInt(0, 2);//玩家子弹类型随机
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
			b->app = AppMatchEnemyType(b);
			auto [ATK, Type, Rad] = RandomAtkAndTypeAndRad(ee, b);
			b->ATK = ATK;
			b->Type = Type;
			b->rad = Rad;
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
	// 1. 删除出界子弹
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(),
			[](bullet* b) {
				if (IsOutRange(b->NowCoord)) {
					AllKindDestroy(b);
					return true;
				}
				return false;
			}),
		bullets.end()
	);

	// 2. 移动子弹
	for (bullet* b : bullets) {
		b->NowCoord = CalcuBulletMove(b,p[0]);
	}

	// 3. 碰撞检测
	for (bullet* b : bullets) {

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

	// 4. 删除被击中死亡的子弹
	bullets.erase(
		std::remove_if(bullets.begin(), bullets.end(),
			[](bullet* b) {
				if (!b->alive) {
					AllKindDestroy(b);
					return true;
				}
				return false;
			}),
		bullets.end()
	);
}
void BulletManager::Render() {

}
void BulletManager::GC() {

}