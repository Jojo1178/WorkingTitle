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
	    
	    Scene();
	    Scene(const Scene& valScene);
	    Scene(int valmaxid,std::vector<Item> valItems,LocalPlayer valPlayer);
	    void load(std::string sceneName);
	    void save(std::string sceneName);
	    int getNextId();
	    void addItem(Item itemToAdd);
	    void render();
	    void clear();
	    Scene &operator=(const Scene&);
    };

} /* wot */

#endif /* __SCENE_H__ */
