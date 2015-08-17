#ifndef __LOCALPLAYER_H__
#define __LOCALPLAYER_H__

#include "LocalPlayerInventory.h"

namespace wot {
    class LocalPlayer : Item {
        public:
            LocalPlayerInventory inventory;
	    
	    LocalPlayer(void);
	    LocalPlayer(const LocalPlayer&);
	    LocalPlayer(LocalPlayerInventory);
	    void operator=(LocalPlayer);
    };

} /* wot */

#endif /* __LOCALPLAYER_H__ */
