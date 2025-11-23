#ifndef AIRPLANE_WARS_BULLET_MANAGER_H
#define AIRPLANE_WARS_BULLET_MANAGER_H

#include <vector>
#include "../core/bullet.h"

class BulletManager {
public:
	std::vector<bullet*> bullets;

	void AddBullet(bullet* b);

	void Update(Player* player, const std::vector<Enemy*>& es);
	void Render();
	void GC();
};

#endif
