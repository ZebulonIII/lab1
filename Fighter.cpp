#include "Fighter.h"
#include <cassert>
#include <sstream>
using namespace std;

Fighter::Fighter() {}
Fighter::~Fighter() {}
string Fighter::getName()  const { return name; }
int Fighter::getMaximumHP()  const { return max_hp; }
int Fighter::getCurrentHP()  const { return cur_hp; }
int Fighter::getStrength()  const { return strength; }
int Fighter::getSpeed()  const { return speed; }
int Fighter::getMagic()  const { return magic; }
void Fighter::takeDamage(int damage) {
    int modifier = speed/4;
    int damage_taken = damage - modifier;
	if (damage_taken <= 0)
		damage_taken = 1;
	assert(damage_taken >= 1);
	cur_hp -= damage_taken;
}
void Fighter::reset() {
	cur_hp = max_hp;
}
void Fighter::regenerate() {
	int modifier = strength / 6;
	if (modifier <= 0)
		modifier = 1;
	cur_hp += modifier;
	assert(modifier >= 1);
	if (cur_hp > max_hp)
		cur_hp = max_hp;
}