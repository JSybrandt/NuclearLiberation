#pragma once

#include"Power.h"
#include"NuclearLiberation.h"

void Power::update(float dt)
{
	if(isActive)
	{
		Drop::update(dt);
	}

}

void Power::onDeath() {
	game->audio->playCue(COCK);
	pickUp();
}

void Power::pickUp() {
	game->player.grantWeaponLevel();
}