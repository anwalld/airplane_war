#include "Mgr-PropMgr.h"
#include"Behavior-PropBehavior.h"
#include "system-engine.h"
#include <random>
#include"system-system.h"
#include "core-Player.h"

void PropManager::Produce() {
		prop* p = new prop;
		p->type = RandomType(p);
		p->NowCoord = RandomProduceCoord(p);
		AddProp(p);
}
void PropManager::AddProp(prop* p) { props.push_back(p); }
bool PropManager::RandomProduce(int dif) {
	double pSuceess = 0.001 + (0.005 - 0.001) * ((1.0 * dif / 10.0) > 1.0 ? 1.0 : (1.0 * dif / 10.0));
	double r = RandomDouble(0, 1);
	return r <= pSuceess;
}
void PropManager::Update(Player* player) {
	if(PropManager::RandomProduce(AllGame::instance().dif))PropManager::Produce();
	props.erase(std::remove_if(props.begin(), props.end(),
		[](prop* p) {
			if (IsOutRange(p->NowCoord)) {
				AllKindDestroy(p);
				return true;
			}
			return false;
		}), props.end());
	for (prop* pp : props) {
		std::pair<double, double>v = PropMoveCoord(pp);
		pp->NowCoord = SystemMove(pp->NowCoord, v.first, v.second);
	}
	for (prop* p : props) {
		if (IsCrash(p->NowCoord, p->rad, player->coord, player->rad)) {
			//Î´¶¨
			p->alive = false;
		}
	}
	props.erase(std::remove_if(props.begin(), props.end(),
		[](prop* p) {
			if (!p->alive) {
				AllKindDestroy(p);
				return true;
			}
			return false;
		}), props.end());
}
void PropManager::Render() {

}
void PropManager::GC() {

}

