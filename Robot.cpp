#include "Robot.h"
#include <math.h>
using namespace std;

Robot::Robot(string name, int max_hp, int str, int speed, int magic) {
	this->name = name;
	this->max_hp = max_hp;
	cur_hp = max_hp;
	strength = str;
	this->speed = speed;
	this->magic = magic;

	bonus_damage = 0;
	max_energy = 2 * magic;
	energy = max_energy;
}

int Robot::getDamage() {
	int damage = strength + bonus_damage;
	bonus_damage = 0;
	return damage;
}

void Robot::reset() {
	Fighter::reset();
	energy = max_energy;
	bonus_damage = 0;
}

bool Robot::useAbility() {
	if (energy < ROBOT_ABILITY_COST)
		return false;
	double temp = (double)energy / (double)max_energy;
	energy -= ROBOT_ABILITY_COST;
	bonus_damage = strength * pow(temp, 4.0);
	return true;
}