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
	    LocalPlayer &operator=(const LocalPlayer&);
    };

} /* wot */

#endif /* __LOCALPLAYER_H__ */
