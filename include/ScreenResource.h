#ifndef __SCREENRESOURCE_H__
#define __SCREENRESOURCE_H__

#include "TextResource.h"

#include <vector>
#include <string>

namespace wot {
    class ScreenResource : public TextResource {
        public:
            std::vector<std::string> content;

            ScreenResource ();
            ScreenResource (const ScreenResource & screenResource);
            virtual ~ScreenResource ();
    
            ScreenResource &operator=(const ScreenResource & screenResource);

            virtual bool load();
            virtual bool free();

            virtual int construct(const std::string & rawPath);
            virtual std::string toString();
    };
} /* wot */

#endif /* __SCREENRESOURCE_H__ */
