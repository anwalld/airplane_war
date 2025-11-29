#include "Mgr-PropMgr.h"
#include"Behavior-PropBehavior.h"
#include "system-engine.h"
#include <random>
#include"system-system.h"
#include "core-Player.h"

void PropManager::Produce(Player*pl) {
		prop* p = new prop;
		std::pair<int, int>TypeAndNum = RandomTypeAndNum(pl, p);
		p->type = TypeAndNum.first;
		p->num = TypeAndNum.second;
		p->NowCoord = RandomProduceCoord(p);
		AddProp(p);
}
void PropManager::AddProp(prop* p) { props.push_back(p); }
bool PropManager::RandomProduce() {
	const int& dif = AllGame::instance().coef;
	double pSuceess = 0.001 + (0.005 - 0.001) * ((1.0 * dif) > 1.0 ? 1.0 : (1.0 * dif));
	double r = RandomDouble(0, 1);
	return r <= pSuceess;
}
static std::unordered_map<prop*, int>UsingProp;
void PropManager::Update(BulletManager& b, EnemyManager& e, Player* player) {
	if(PropManager::RandomProduce())PropManager::Produce(player);
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
		switch (p->type) {
		case 0: {
			switch (p->num) {
			case 0: { PropEffect_DecreaseVShoot(player, p); break; }
			case 1: { PropEffect_IncreaseBulletDamage(player, p); break; }
			case 2: { PropEffect_IncreasePlaneMaxHp(player, p); break; }
			case 3: { PropEffect_IncreasePlaneSpeed(player, p); break; }
			default: { break; }
			}
			p->alive = false;
			break;
		}
		case 1:{
			switch (p->num) {
			case 0: { PropEffect_Heal(player, p); break; }
			case 1: { PropEffect_ClearScreen(b,e,p); break; }
			case 2: { PropEffect_FullScreenBomb(e,p); break; }
			default: { break; }
			}
			p->alive = false;
			break;
		}
		case 2: {
			switch (p->num) {
			case 0: { PropEffect_LaserWeapon(player, p); break; }
			case 1: { PropEffect_SuperBullet(player, p); break; }
			case 2: { PropEffect_DecreaseDif(p); break; }
			case 3: { PropEffect_Invincible(player, p); break; }
			default: { break; }
			}
			UsingProp[p] = AllGame::instance().GameTime;
			break;
		}
		default: { break; }
		}
	}
		}
	for (auto& [p, t] : UsingProp) {
		if (AllGame::instance().GameTime - t >= p->CD) {
			switch (p->num) {
			case 0: {
				player->Vshoot /= 0.1;
				player->AddATK += 5;
				break;
			}
			case 1: {
				player->atk -= 20;
				break;
			}
			case 2: {
				AllGame::instance().AllKill += 100;
				break;
			}
			case 3: {
				player->camp = 0;
				break;
			}
			default: { break; }
			}
			UsingProp.erase(p);
			p->alive = false;
		}
	}
		
	props.erase(std::remove_if(props.begin(), props.end(),
		[](prop* p) {
			if (!p->alive) {
				if (UsingProp.find(p) != UsingProp.end())UsingProp.erase(p);
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

