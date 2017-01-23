#pragma once
#include "Cleric.h"

using namespace std;

Cleric::Cleric(string name, int max_hp, int str, int speed, int magic) {
	this->name = name;
	this->max_hp = max_hp;
	cur_hp = max_hp;
	strength = str;
	this->speed = speed;
	this->magic = magic;
	max_mana = 5 * magic;
	mana = max_mana;
}

void Cleric::reset() {
	Fighter::reset();
	mana = max_mana;
}

void Cleric::regenerate() {
	Fighter::regenerate();
	int modifier = magic / 5;
	if (modifier == 0)
		modifier = 1;
	mana += modifier;
	if (mana > max_mana)
		mana = max_mana;
}

bool Cleric::useAbility() {
	if (mana < CLERIC_ABILITY_COST)
		return false;
	mana -= CLERIC_ABILITY_COST;
	int modifier = magic / 3;
	if (modifier <= 0)
		modifier = 1;
	cur_hp += modifier;
	if (cur_hp > max_hp)
		cur_hp = max_hp;
	return true;
}