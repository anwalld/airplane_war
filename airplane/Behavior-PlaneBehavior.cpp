#include "Behavior-PlaneBehavior.h"
#include "system-engine.h"

bool ShouldFire(plane* p) {
	if (p->Vshoot <= 0) return false;
	return AllGame::instance().frameCount % p->Vshoot == 0;
}
