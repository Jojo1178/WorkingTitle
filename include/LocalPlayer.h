#ifndef __LOCALPLAYER_H__
#define __LOCALPLAYER_H__

#include "LocalPlayerInventory.h"

namespace wot {
    class LocalPlayer : Item {
        public:
            LocalPlayerInventory inventory;
	    
	    LocalPlayer(void);
	    LocalPlayer(LocalPlayerInventory valInventory);
    };

} /* wot */

#endif /* __LOCALPLAYER_H__ */
