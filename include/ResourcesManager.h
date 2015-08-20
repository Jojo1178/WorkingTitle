#ifndef __RESOURCESMANAGER_H__
#define __RESOURCESMANAGER_H__

#include "ResourceType.h"
#include "Resource.h"

#include <functional>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

namespace wot {
    class ResourcesManager {
        public:
            static std::map<std::string, std::function<void(std::string)> > parseactions;

            static std::string resourcePath;
            static std::map<ResourceType, std::map<std::string, Resource> > resources;

            ResourcesManager ();
            virtual ~ResourcesManager ();

            static void feedResources(std::string resourcePath);
            static void clearResources();
            static void printResources();

            static Resource * getResource(ResourceType type, std::string key);
    };
} /* wot */

#endif /* __RESOURCESMANAGER_H__ */
