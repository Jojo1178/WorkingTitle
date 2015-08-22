#ifndef __TEXTRESOURCE_H__
#define __TEXTRESOURCE_H__

#include "Resource.h"

namespace wot {
    class TextResource : public Resource {
        public:
            TextResource ();
            TextResource (const TextResource & textResource);
            virtual ~TextResource ();
    
            TextResource &operator=(const TextResource & textResource);

            virtual bool load();
            virtual bool free();

            int construct(const std::string & rawPath);
    };
} /* wot */

#endif /* __TEXTRESOURCE_H__ */
