#include "Scene.h"

namespace wot {
    Scene::Scene(void) {
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
    }
    void Scene::render(){
	
    }
    void Scene::clear(){
	
    }

    void Scene::operator=(Scene valScene){
	maxid = valScene.maxid;
	items = valScene.items;
        player = valScene.player;
    }
    
} /* wot */
