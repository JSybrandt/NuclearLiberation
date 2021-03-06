#pragma once
#include"Actor.h"
#include"Controls.h"
#include "mathUtil.h"

class NuclearLiberation;

namespace playerNS{
	const float MAX_SPEED = 55;
	const float FRICTION_RATE = 150;
	const float ACCEL_RATE = 150;
	const float DEFAULT_COOLDOWN = 0.2;
	const float MAX_ROTATION_ANGLE = .7;
	const float ROTATION_EPS = 0.05;
	const float ROTATION_SPEED = 5;
	const Vector3 FIRE_SPEED(90,0,0);
	const float MAX_AIR = 30; //AIR DEPLETES AT 1 UNIT PER SECOND
	const Vector3 HELIX_DISP(3,0,0);
	const int MAX_WEAPON_LEVEL = 5;
	const float SHIELD_SIZE = 4;
};

class Player : public virtual Actor
{
public:

	void init(NuclearLiberation*game,Geometry *hull, Geometry *point,Geometry *shield, float r, Controls c);
	void update(float dt);
	void draw(ID3D10EffectMatrixVariable* fx, Matrix& camera, Matrix& projection, ID3D10EffectTechnique* mTech);
	void refillAir();
	float getAir(){return airLevel;}
	int getLives(){return lives;}
	int& setLives() {return lives;}
	float topDef(float x);
	float bottomWall(float x);


	void resetAll(){weaponLevel=1;weaponCooldown=0;fireCounter=0;refillAir(); health = 1;shieldActive=false; lives = 3;}
	void refresh(){weaponCooldown=0;fireCounter=0;refillAir();}

	void grantWeaponLevel(){weaponLevel = min(weaponLevel+1,playerNS::MAX_WEAPON_LEVEL);}
	void grantShield(){shieldActive = true;}

	void takeDamage();

private:
	Actor hitBoxIndicatior,shieldIndicator;
	Vector3 input;
	Controls controls;
	int weaponLevel;
	float weaponCooldown;
	Vector3 accel;
	Vector3 oldPos;
	float airLevel;
	int fireCounter;//used to distinguish shots when firing
	float fireAngle;//used to make helix
	int lives;

	bool drowning, airAudio;
	bool shieldActive;
	void fireBullets();

};