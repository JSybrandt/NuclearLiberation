#pragma once
#include "Drop.h"

class Shield : public virtual Drop
{
public:
	void update(float dt);
	void onDeath();
	void pickUp();
};