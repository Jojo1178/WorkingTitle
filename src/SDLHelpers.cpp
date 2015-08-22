#include "SDLHelpers.h"

#include <iostream>

#include "ApplicationStateMachine.h"

namespace wot {
    SDL_Surface * SDLHelpers::loadBitmap(std::string path) {
        SDL_Surface * ret = NULL;

        SDL_Surface * load = IMG_Load(path.c_str());
        if (load == NULL) {
            std::cerr << "Unable to load image " << path << std::endl;
        } else {
            if (ApplicationStateMachine::getScreen() != NULL) {
                ret = SDL_ConvertSurface(load, ApplicationStateMachine::getScreen()->format, NULL);
                if (ret == NULL) {
                    std::cerr << "Error optimizing the image. [" << SDL_GetError() <<
                        "]" << std::endl;
                }
                SDL_FreeSurface(load);
            }
        }
        return ret;
    }
} /* wot */
