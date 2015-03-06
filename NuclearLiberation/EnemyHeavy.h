#pragma once
#include "Actor.h"

namespace EnemyHeavyNS{
	const float SPEED = 20;
	const float BULLET_SPEED = 50;
	const float FIRE_RATE = 1;
	const float FIRE_CHANCE = 50;
	const float ACTIVATION_RANGE = 100;
};

class EnemyHeavy: public virtual Actor
{
public:
	EnemyHeavy():Actor(){playerSeen=false;cooldown=0;MAX_HEALTH = 100.0f; health = MAX_HEALTH; }
	void update(float dt);
private:
	float cooldown;
	bool playerSeen;
};