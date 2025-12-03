#pragma once
#ifndef AIRPLANE_WARS_PROP_MANAGER_H
#define AIRPLANE_WARS_PROP_MANAGER_H

#include <vector>
#include "core-prop.h"
#include<unordered_map>
#include"Mgr-BulletMgr.h"
#include"Mgr-EnemyMgr.h"
#include"easyx.h"
#include"Res-GameRes.h"
#include"system-system.h"
class PropManager {
public:
	std::vector<prop*> props;
	bool RandomProduce();
	void Produce(Player*pl);
	void AddProp(prop* p);
	void Update(BulletManager& b, EnemyManager& e, Player* player);
	void Render();
	void GC();
};


#endif
