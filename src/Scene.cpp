#include "Scene.h"

#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"

namespace wot {
    Scene::Scene() {
        maxid = 0;
        player = LocalPlayer();
    }

    Scene::Scene(const Scene& valScene){
	maxid = valScene.maxid;
	items = valScene.items;
        player = valScene.player;
    }

    Scene::Scene(int valmaxid,std::vector<Item> valItems,LocalPlayer valPlayer) {
	maxid = valmaxid;
	items = valItems;
        player = valPlayer;
    }

    void Scene::load(std::string sceneName){
	
    }
    void Scene::save(std::string sceneName){
	
    }
    int Scene::getNextId(){
	
    }
    void Scene::addItem(Item itemToAdd){
	if(items.empty() || !itemToAdd.stackable)	
		items.push_back(itemToAdd);
	else{
		for (std::vector<Item>::iterator it = items.begin(); it != items.end(); ++it){
			if(*it == itemToAdd){
				(*it).quantity++;
				return;
			}
		}
		items.push_back(itemToAdd);
	}
        std::sort(items.begin(),items.end());
    }
    void Scene::render(SDL_Surface * surface){
        SDL_Surface *image = NULL, *rotation = NULL;
        for (std::vector<Item>::iterator it=items.begin(); it!=items.end(); ++it){
            Item varitem = *it;
//TODO: LOAD image
            //image = IMG_Load(varitem.resource.rawPath.c_str());
            image = IMG_Load("image.bmp");
            SDL_Rect r;
            Coordinates newCoor = varitem.coordinates;
            newCoor = newCoor.isoToTwoD(
                newCoor,
                ApplicationPreferencesManager::getIntegerPreference("tileWidth", DEFAULT_WIDTH),
                ApplicationPreferencesManager::getIntegerPreference("tileHeight", DEFAULT_WIDTH),
                ApplicationPreferencesManager::getIntegerPreference("width", DEFAULT_WIDTH)
            );
            r.x = newCoor.x;
            r.y = newCoor.y;
            r.w = ApplicationPreferencesManager::getIntegerPreference("tileWidth", DEFAULT_WIDTH);
            r.h = ApplicationPreferencesManager::getIntegerPreference("tileHeight", DEFAULT_WIDTH);
            image->w = r.w+13;
            image->h = r.h+13;
            rotation = rotozoomSurface(image, 45, 1.0, 1);
            SDL_BlitSurface(rotation, NULL, surface, &r); 
            SDL_FreeSurface(rotation);
            SDL_FreeSurface(image);
        }
    }
    void Scene::clear(){
	
    }

    Scene & Scene::operator=(const Scene& valScene){
	maxid = valScene.maxid;
	items = valScene.items;
        player = valScene.player;
        return *this;
    }
    
} /* wot */
