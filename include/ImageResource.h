#ifndef __IMAGERESOURCE_H__
#define __IMAGERESOURCE_H__

#include "TextResource.h"

#include <string>

extern "C" {
#include <SDL.h>
#include <SDL_image.h>
}

namespace wot {
    class ImageResource : public TextResource {
        protected:
            std::string bitmapPath;
            SDL_Surface * bitmap;
        public:
            ImageResource ();
            ImageResource (const ImageResource & imageResource);
            virtual ~ImageResource ();
    
            ImageResource &operator=(const ImageResource & imageResource);

            virtual bool load();
            virtual bool free();

            virtual int construct(const std::string & rawPath);
            virtual std::string toString();

            virtual SDL_Surface * getBitmap();
    };
} /* wot */

#endif /* __IMAGERESOURCE_H__ */
