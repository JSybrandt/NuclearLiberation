#include "Enemy.h"
#include "NuclearLiberation.h"
using namespace EnemyNS;

void Enemy::onDeath() {
	int rander = random(3);
	switch(rander) {
		case 1:
			game->audio->playCue(EXP1);
			break;
		case 2:
			game->audio->playCue(EXP2);
			break;
		case 3:
			game->audio->playCue(EXP3);
			break;
		default:
			game->audio->playCue(EXP1);
	}
}