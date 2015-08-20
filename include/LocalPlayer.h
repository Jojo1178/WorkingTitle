#ifndef __LOCALPLAYER_H__
#define __LOCALPLAYER_H__

#include "LocalPlayerInventory.h"

namespace wot {
    class LocalPlayer : Item {
        public:
            LocalPlayerInventory inventory;
	    
	    LocalPlayer();
	    LocalPlayer(const LocalPlayer& valPlayer);
	    LocalPlayer(LocalPlayerInventory valInventory);
	    void operator=(LocalPlayer valPlayer);
    };

} /* wot */

#endif /* __LOCALPLAYER_H__ */
