#ifndef __LOCALPLAYERINVENTORY_H__
#define __LOCALPLAYERINVENTORY_H__

#include "Item.h"
#include <vector>

namespace wot {
    class LocalPlayerInventory {
        public:
            int capacity;
	    std::vector<Item> content;
	    
	    LocalPlayerInventory(void);
	    LocalPlayerInventory(const LocalPlayerInventory&);			
	    LocalPlayerInventory(int, std::vector<Item>);
	    Item getItem(int);
	    void addItem(Item);
	    void removeItem(int);
	    void operator=(LocalPlayerInventory);
    };
} /* wot */

#endif /* __LOCALPLAYERINVENTORY_H__ */
