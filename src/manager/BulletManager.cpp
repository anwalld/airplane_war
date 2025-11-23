#include "manager/BulletManager.h"
#include "system/system.h"
#include "Enemy.h"
#include "core/bullet.h"
#include "Player.h"
#include"behavior/BulletBehavior.h"
#include"behavior/PlaneBehavior.h"
void BulletManager::AddBullet(bullet* b) {
	bullets.push_back(b);
}
void BulletManager::Produce(const std::vector<Player*>&p, const std::vector<Enemy*>& es) {
	for (Player*pp :p) {
		if (ShouldFire(pp)) {
			bullet* b = new bullet();
			b->app=AppMatchEnemyType(b);
			b->vx=InitVyAndVy(b).first;
			b->vy=InitVyAndVy(b).second;
			b->camp=0;
			b->NowCoord=pp->coord;
			b->alive=true;
			AddBullet(b);
		}
	}
	for (Enemy*ee:es) {
		if (ShouldFire(ee)) {
			bullet* b = new bullet();
			b->app=AppMatchEnemyType(b);
			b->vx=InitVyAndVy(b).first;
			b->vy=InitVyAndVy(b).second;
			b->camp=1;
			b->NowCoord=ee->coord;
			b->alive=true;
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
		b->NowCoord=SystemMove(b->NowCoord,b->vx,b->vy);
	}

	// 3. 碰撞检测
	for (bullet* b : bullets) {

		if (b->camp == 0) {
			// 玩家子弹 → 打敌机
			for (Enemy* e : es) {
				if (IsSameCamp(e->camp,b->camp)) {
					e->NowHp -= b->ATK;
					b->alive = false;
				}
			}
		}
		else {
			// 敌机子弹 → 打玩家
			for (Player* p : p) {
				if (IsSameCamp(p->camp,b->camp)) {
					p->NowHp -= b->ATK;
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



