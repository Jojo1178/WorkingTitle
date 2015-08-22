#ifndef __SDLHELPERS_H__
#define __SDLHELPERS_H__

#include <string>

extern "C" {
#include <SDL.h>
#include <SDL_image.h>
}

namespace wot {
    class SDLHelpers {
        public:
            static SDL_Surface * loadBitmap(std::string path);
    };
} /* wot */

#endif /* __SDLHELPERS_H__ */
