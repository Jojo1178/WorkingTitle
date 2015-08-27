#ifndef __BUTTONRESOURCE_H__
#define __BUTTONRESOURCE_H__

#include "ImageResource.h"

namespace wot {
    class ButtonResource : public ImageResource {
        public:
            ButtonResource ();
            ButtonResource (const ButtonResource & buttonResource);
            virtual ~ButtonResource ();
    
            ButtonResource &operator=(const ButtonResource & buttonResource);

            virtual bool load();
            virtual bool free();

            virtual int construct(const std::string & rawPath);
    };
} /* wot */

#endif /* __BUTTONRESOURCE_H__ */
