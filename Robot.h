#pragma once
#include "Fighter.h"

using namespace std;

class Robot : public Fighter {
private:
	int bonus_damage;
	int energy;
	int max_energy;
public:
	Robot(string, int, int, int, int);
	int getDamage();
	void reset();
	bool useAbility();
};