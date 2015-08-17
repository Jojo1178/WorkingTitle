#include "LocalPlayerInventory.h"

namespace wot {
    LocalPlayerInventory::LocalPlayerInventory(void) {
        capacity = 0;
    }

   LocalPlayerInventory::LocalPlayerInventory(const LocalPlayerInventory& valLocalPlayerInventory) {
        capacity = valLocalPlayerInventory.capacity;
	content = valLocalPlayerInventory.content;
    }

    LocalPlayerInventory::LocalPlayerInventory(int valCapacity, std::vector<Item> valContent) {
        capacity = valCapacity;
	content = valContent;
    }

    Item LocalPlayerInventory::getItem(int place){
	return content.at(place);
    }

    void LocalPlayerInventory::addItem(Item itemToAdd){
	if(content.empty() || !itemToAdd.stackable)	
		content.push_back(itemToAdd);
	else{
		for (std::vector<Item>::iterator it = content.begin(); it != content.end(); ++it){
			if(*it == itemToAdd){
				(*it).quantity++;
				return;
			}
		}
		content.push_back(itemToAdd);
	}
    }

    void LocalPlayerInventory::removeItem(int place){
	content.erase(content.begin() + place);
    }

   void LocalPlayerInventory::operator=(LocalPlayerInventory valLocalPlayerInventory){
        capacity = valLocalPlayerInventory.capacity;
	content = valLocalPlayerInventory.content;
   }
    
} /* wot */
