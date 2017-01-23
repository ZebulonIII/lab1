#include "Archer.h"
using namespace std;

Archer::Archer(string name, int max_hp, int str, int speed, int magic) {
	this->name = name;
	this->max_hp = max_hp;
	strength = str;
	this->speed = speed;
	orig_speed = speed;
	this->magic = magic;
	cur_hp = max_hp;
}

void Archer::reset() {
	Fighter::reset();
	speed = orig_speed;
}

bool Archer::useAbility() {
	speed++;
	return true;
}