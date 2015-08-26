#include "Scene.h"

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
    void Scene::render(){
        std::cout << "items contains:";
        SDL_Surface *image = NULL, *rotation = NULL;
        for (std::vector<Item>::iterator it=items.begin(); it!=items.end(); ++it){
            Item varitem = *it;
            image = IMG_Load(varitem.resource.rawPath.c_str());
            SDL_Rect r;
            Coordinates newCoor = varitem.coordinates;
//TODO: Get Windows Resolution
            //newCoor = newCoor.isoToTwoD(newCoor,tileW/2,tileH/2,800/2);
            r.x = newCoor.x;
            r.y = newCoor.y;
            //r.w = tileW;
            //r.h = tileH;
            rotation = rotozoomSurface(image, 45, 1.0, 1);
//TODO: SDL_GetWindowSurface(MainWindow)
            //SDL_BlitSurface(rotation, NULL, screen, &r); 
            SDL_FreeSurface(rotation); 
//TODO: Get MainWindow
            //SDL_UpdateWindowSurface(MainWindow);
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
