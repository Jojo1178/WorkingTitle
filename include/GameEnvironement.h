#ifndef __GAMEENVIRONEMENT_H__
#define __GAMEENVIRONEMENT_H__

#include "Scene.h"
#include "LocalPlayer.h"
#include <string>

namespace wot {
    class GameEnvironement {
        public:
	    Scene scene;
	    
	    GameEnvironement(void);
	    GameEnvironement(const GameEnvironement&);
	    GameEnvironement(Scene);
	    void save(std::string);
	    void operator=(GameEnvironement);
    };

} /* wot */

#endif /* __GAMEENVIRONEMENT_H__ */
