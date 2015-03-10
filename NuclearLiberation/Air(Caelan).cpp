#pragma once

#include"Air.h"
#include"NuclearLiberation.h"

void Air::update(float dt)
{
	if(isActive)
	{
		Drop::update(dt);
	}

}

void Air::onDeath() {
	//game->audio->playCue(BUB);
	pickUp();
}

void Air::pickUp() {
	game->player.refillAir();
}