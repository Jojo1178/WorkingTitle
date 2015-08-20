#include "GameEnvironement.h"

	    	    

namespace wot {
    GameEnvironement::GameEnvironement() {
        scene = Scene();
    }

    GameEnvironement::GameEnvironement(const GameEnvironement& valGameEnvironement){
	scene = valGameEnvironement.scene;
    }

    GameEnvironement::GameEnvironement(Scene valScene){
	scene = valScene;
    }

    void GameEnvironement::save(std::string sceneName){
	
    }

    GameEnvironement & GameEnvironement::operator=(const GameEnvironement& valGameEnvironement){
	scene = valGameEnvironement.scene;
        return *this;
    }
    
} /* wot */
