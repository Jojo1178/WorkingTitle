#include "Item.h"

#include <iostream>

namespace wot {
	Item::Item(void){
		id = 0;
		name = "";
		stackable = false;
		quantity = 0;
		coordinates = Coordinates();
		resource = Resource();
	}

	Item::Item(int valId, std::string valName, bool valStackable, unsigned int valQuantity, Coordinates valCoordinates, Resource valResource){
		id = valId;
		name = valName;
		stackable = valStackable;
		quantity = valQuantity;
		coordinates = valCoordinates;
		resource = valResource;
	}

	Item::Item(const Item& valItem){
		id = valItem.id;
		name = valItem.name;
		stackable = valItem.stackable;
		quantity = valItem.quantity;
		coordinates = valItem.coordinates;
		resource = valItem.resource;
	}

	void Item::operator=(Item val){
		id = val.id;
		name = val.name;
		stackable = val.stackable;
		quantity = val.quantity;
		coordinates = val.coordinates;
		resource = val.resource;
	}

	bool operator==(Item const& a,Item const& b){
		return a.id == b.id;
	}

        bool operator<(Item const& a,Item const& b){
                return a.coordinates < b.coordinates;
        }
} /* wot */
