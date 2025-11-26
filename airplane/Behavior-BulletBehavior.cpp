#include "Behavior-BulletBehavior.h"
#include <random>
#include "system-system.h"
#include"core-bullet.h"
static std::random_device rd;
static std::mt19937 gen(rd());
int AppMatchEnemyType(bullet* b) {
	int x = 3;
	std::uniform_int_distribution<int> dis(0, x - 1);
	int ans = dis(gen);
	return ans;
}
std::pair<int, int> InitVyAndVy(bullet* b) {
	return std::make_pair(0, 200 / 120);
}
std::pair<int, int> CalcuBulletMove(pair<int, int>v, bullet* b) {
	int vx = InitVyAndVy(b).first;
	int vy = InitVyAndVy(b).second;
	return SystemMove(b->NowCoord, vx, vy);
}
