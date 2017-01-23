#pragma once
#include "Fighter.h"

using namespace std;

class Archer : public Fighter {
private:
	int orig_speed;
public:
    Archer(string,int,int,int,int);
	int getDamage() { return speed; }
	void reset();
	bool useAbility();
};