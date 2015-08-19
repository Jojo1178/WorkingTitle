#ifndef __ITEM_H__
#define __ITEM_H__

#include "Coordinates.h"
#include "Resource.h"
#include <string>

namespace wot {
    class Item {
        public:
            int id;
	    std::string name;
	    bool stackable;
	    unsigned int quantity;
	    Coordinates coordinates;
	    Resource resource;
	    
	    Item(void);
	    Item(const Item&);
	    Item(int, std::string, bool, unsigned int, Coordinates, Resource);

	    void operator=(Item);
    };

    bool operator==(Item const&,Item const&);
    bool operator<(Item const&,Item const&);
} /* wot */

#endif /* __ITEM_H__ */
