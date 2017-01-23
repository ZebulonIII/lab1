#pragma once
#include "Fighter.h"

using namespace std;

class Cleric : public Fighter {
private:
	int mana;
	int max_mana;
public:
	Cleric(string, int, int, int, int);
	int getDamage() { return magic; }
	void reset();
	void regenerate();
	bool useAbility();
};