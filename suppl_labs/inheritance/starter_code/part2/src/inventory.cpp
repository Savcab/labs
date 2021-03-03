#include "inventory.h"
#include <iostream>

using namespace std;
Inventory::Inventory() : vector<Item>()
{
	// nothing to do here
}

/* Add an item to the inventory with the given name and amount. */
void Inventory::addItem(std::string name, int amount)
{
	for(unsigned int i = 0 ; i < vector<Item>::size() ; i++){
		if(vector<Item>::operator[](i).name == name){
			vector<Item>::operator[](i).amount += amount;
			return;
		}
	}
	vector<Item>::push_back(Item(name, amount));
}

/* Remove all items with this name from the inventory. */
void Inventory::removeItem(std::string name)
{
	for(unsigned int i = 0 ; i < vector<Item>::size() ; i++){
		if(vector<Item>::operator[](i).name == name){
			vector<Item>::erase(vector<Item>::begin() + i);
			return;
		}
	}
}

/* Return the number of items with this name from the inventory. */
int Inventory::getNumItems(std::string name)
{
	return vector<Item>::size();
}

/* Print all the items in this format:
	key value
	key value
	key value
*/
void Inventory::printAllItems()
{
	for(vector<Item>::iterator it = vector<Item>::begin() ; it != vector<Item>::end() ; it++){
		cout << it->name << " " << it->amount << endl;
	}
}