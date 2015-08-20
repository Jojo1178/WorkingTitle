#include "LocalPlayer.h"


namespace wot {
    LocalPlayer::LocalPlayer() {

	id = 1;
	name = "Player";
	stackable = false;
	quantity = 1;
	coordinates = Coordinates();
	resource = Resource();

        inventory = LocalPlayerInventory();
    }

    LocalPlayer::LocalPlayer(LocalPlayerInventory valInventory) {
	id = 1;
	name = "Player";
	stackable = false;
	quantity = 1;
	coordinates = Coordinates();
	resource = Resource();

        inventory = valInventory;
    }

    LocalPlayer::LocalPlayer(const LocalPlayer& valPlayer){
	id = valPlayer.id;
	name = valPlayer.name;
	stackable = valPlayer.stackable;
	quantity = valPlayer.quantity;
	coordinates = valPlayer.coordinates;
	resource = valPlayer.resource;
        inventory = valPlayer.inventory;
    }
    
    void LocalPlayer::operator=(LocalPlayer valPlayer){
	id = valPlayer.id;
	name = valPlayer.name;
	stackable = valPlayer.stackable;
	quantity = valPlayer.quantity;
	coordinates = valPlayer.coordinates;
	resource = valPlayer.resource;
        inventory = valPlayer.inventory;
    }    
} /* wot */
