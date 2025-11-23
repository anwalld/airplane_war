#ifndef AIRPLANE_WARS_PROP_MANAGER_H
#define AIRPLANE_WARS_PROP_MANAGER_H

#include <vector>
#include "../core/prop.h"

class PropManager {
public:
	std::vector<prop*> props;

	void AddProp(prop* p);

	// 道具随机生成
	void RandomProduce(int dif);

	void Update(Player* player);
	void Render();
	void GC();
};


#endif
