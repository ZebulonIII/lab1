#include "Arena.h"
#include "Fighter.h"
#include "Archer.h"
#include "Cleric.h"
#include "Robot.h"

#include <sstream>

using namespace std;

//info format:
//(name) (type) (maximum hit points) (strength) (speed) (magic)
//Example: Xephos A 200 13 21 10
bool Arena::addFighter(string info) {
	stringstream ss(info);
	string name;
	ss >> name;
	if (getFighter(name) != NULL) { //check if fighter in collection
		return false;
	}
	//define new Fighter
	char type;
	int max_hit_points, strength, speed, magic;
	ss >> type >> max_hit_points >> strength >> speed >> magic;

	//check valid input
	if (!ss.eof()) //extra input
		return false;
	if (max_hit_points <= 0)
		return false;
	if (strength <= 0)
		return false;
	if (speed <= 0)
		return false;
	if (magic <= 0)
		return false;

	switch (type) {
	case 'A':
		fighters.push_back(new Archer(name, max_hit_points, strength, speed, magic));
		break;
	case 'C':
		fighters.push_back(new Cleric(name, max_hit_points, strength, speed, magic));
		break;
	case 'R':
		fighters.push_back(new Robot(name, max_hit_points, strength, speed, magic));
		break;
	default: //incorrect type
		return false;
	};

	return true;
}
bool Arena::removeFighter(string name) {
	for (vector<FighterInterface*>::iterator iter = fighters.begin(); iter != fighters.end(); iter++) {
		if ((*iter)->getName() == name) {
			fighters.erase(iter);
			return true;
		}
	}
	return false;
}
FighterInterface* Arena::getFighter(string name) {
	for (vector<FighterInterface*>::iterator iter = fighters.begin(); iter != fighters.end(); iter++) {
		if ((*iter)->getName() == name)
			return *iter;
	}
	return NULL;
}
int Arena::getSize() {
	return fighters.size();
}