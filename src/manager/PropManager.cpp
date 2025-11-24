#include "manager/PropManager.h"
#include"Behavior/PropBehavior.h"
#include "system/engine.h"
#include <random>

#include "Player.h"

void PropManager::Produce() {
	prop* p = new prop;
	if (RandomProduce(AllGame::instance().dif))
	{
		p->type = RandomType(p);
		p->NowCoord = RandomProduceCoord(p);
		AddProp(p);
	}
}
void PropManager::AddProp(prop* p) {props.push_back(p);}
bool PropManager::RandomProduce(int dif) {
	std::vector<int>weights(4);
	weights[0]=10;weights[1]=15;weights[2]=50;weights[3]=25;
	int ans=-1;
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> dist(0, 100);
	int x = dist(mt);
	if (x<=weights[0])ans=0;
	else if (x<=weights[1]+weights[0])ans=1;
	else if (x<=weights[2]+weights[1]+weights[0])ans=2;
	else if (x<=weights[3]+weights[2]+weights[1]+weights[0])ans=3;
	else ans=-1;
	return ans==0?true:false;
}
void PropManager::Update(Player* player) {
	props.erase(std::remove_if(props.begin(), props.end(),
		[](prop* p) {
			if (IsOutRange(p->NowCoord)) {
				AllKindDestroy(p);
				return true;
			}
			return false;
		}),props.end());
	for (prop* pp: props) {
		auto [vx,vy]=RandonMove(pp);
		pp->NowCoord=SystemMove(pp->NowCoord,vx,vy);
	}
	for (prop* p: props) {
		if (IsCrash(p->NowCoord,p->rad,player->coord,player->rad)) {
			//未定
			p->alive=false;
		}
	}
	props.erase(std::remove_if(props.begin(), props.end(),
		[](prop* p) {
			if (!p->alive) {
				AllKindDestroy(p);
				return true;
			}
			return false;
		}),props.end());
}
void PropManager::Render() {

}
void PropManager::GC() {

}

