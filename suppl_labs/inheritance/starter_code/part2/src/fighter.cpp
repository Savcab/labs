#include "fighter.h"

using namespace std;

Fighter::Fighter(string name) : Player(name) {
	// nothing to do here
}

void Fighter::doAction(Player *target) {
	target->setHP(target->getHP() - 300);
	if(target->getHP() < 0){
		target->setHP(0);
	}
}