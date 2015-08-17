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
	    
	    Item(int valId, 
		std::string valName, 
		bool valStackable, 
		unsigned int valQuantity, 
		Coordinates valCoordinates, 
		Resource Valresource);

	    void operator=(Item val);
    };

    bool operator==(Item const& a,Item const& b);
} /* wot */

#endif /* __ITEM_H__ */
