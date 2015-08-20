#ifndef __GAMEENVIRONEMENT_H__
#define __GAMEENVIRONEMENT_H__

#include "Scene.h"
#include "LocalPlayer.h"
#include <string>

namespace wot {
    class GameEnvironement {
        public:
	    Scene scene;
	    
	    GameEnvironement();
	    GameEnvironement(const GameEnvironement& valGameEnvironement);
	    GameEnvironement(Scene valScene);
	    void save(std::string sceneName);
	    GameEnvironement &operator=(const GameEnvironement&);
    };

} /* wot */

#endif /* __GAMEENVIRONEMENT_H__ */
