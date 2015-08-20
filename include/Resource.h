#ifndef __RESOURCE_H__
#define __RESOURCE_H__

#include <string>
#include <ostream>

#include "ResourceType.h"

namespace wot {
    class Resource {
        protected:
            bool loaded;
        public:
            ResourceType resourceType;
            std::string rawPath;

            std::string name;
            std::string description;

            Resource();
            Resource(const Resource & resource);
            ~Resource();

            Resource &operator=(const Resource&);

            /*
             * This function returns 1 or more if it was successful
             * returns 0 otherwise
             */
            virtual int construct(const std::string & rawPath);
            virtual std::string toString();
    };
} /* wot */

#endif /* __RESOURCE_H__ */
