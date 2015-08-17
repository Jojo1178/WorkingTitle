#include "GameEnvironement.h"

	    	    

namespace wot {
    GameEnvironement::GameEnvironement(void) {
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

    void GameEnvironement::operator=(GameEnvironement valGameEnvironement){
	scene = valGameEnvironement.scene;
    }
    
} /* wot */
