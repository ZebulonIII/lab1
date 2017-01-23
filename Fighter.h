#pragma once
#include "FighterInterface.h"

using namespace std;

class Fighter : public FighterInterface {
protected:
	string name;
    int max_hp, cur_hp, strength, speed, magic;
public:
    Fighter();
	~Fighter();
	string getName() const;
    int getMaximumHP() const;
    int getCurrentHP() const;
    int getStrength() const;
    int getSpeed() const;
    int getMagic() const;
	int getDamage() = 0;
    void takeDamage(int);
	void reset();
    void regenerate();
    bool useAbility() = 0;
};