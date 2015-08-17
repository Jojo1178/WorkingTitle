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
	    LocalPlayerInventory(int valCapacity, std::vector<Item> valContent);
	    Item getItem(int place);
	    void addItem(Item itemToAdd);
	    void removeItem(int place);
    };
} /* wot */

#endif /* __LOCALPLAYERINVENTORY_H__ */
