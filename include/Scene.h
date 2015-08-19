#ifndef __SCENE_H__
#define __SCENE_H__

#include "Item.h"
#include "LocalPlayer.h"
#include <vector>
#include <algorithm> 

namespace wot {
    class Scene {
        public:
	    int maxid;
	    std::vector<Item> items;
	    LocalPlayer player;
	    
	    Scene(void);
	    Scene(const Scene&);
	    Scene(int,std::vector<Item>,LocalPlayer);
	    void load(std::string);
	    void save(std::string);
	    int getNextId();
	    void addItem(Item);
	    void render();
	    void clear();
	    void operator=(Scene);
    };

} /* wot */

#endif /* __SCENE_H__ */
