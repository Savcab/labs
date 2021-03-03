#include "healer.h"

using namespace std;

Healer::Healer(string name) : Player(name) {
	// nothing to do here
}

//heal 10 HP
void Healer::doAction(Player *target) {
	target->setHP(target->getHP() + 200);
	if(target->getHP() > target->getMaxHP()){
		target->setHP(target->getMaxHP());
	}
}