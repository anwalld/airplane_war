#ifndef AIRPLANE_WARS_PROP_MANAGER_H
#define AIRPLANE_WARS_PROP_MANAGER_H

#include <vector>
#include "../core/prop.h"
class PropManager {
public:
	std::vector<prop*> props;
	bool RandomProduce(int dif);
	void Produce();
	void AddProp(prop* p);
	void Update(Player* player);
	void Render();
	void GC();
};


#endif
