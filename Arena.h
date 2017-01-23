#pragma once
#include "ArenaInterface.h"
#include <vector>

using namespace std;

class Arena : public ArenaInterface {
private:
    vector<FighterInterface*> fighters;
public:
	Arena() {}
    bool addFighter(string);
    bool removeFighter(string);
    FighterInterface* getFighter(string);
    int getSize();
};