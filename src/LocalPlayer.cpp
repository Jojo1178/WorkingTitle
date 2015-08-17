#include "LocalPlayer.h"


namespace wot {
    LocalPlayer::LocalPlayer(void) {

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
    
} /* wot */
