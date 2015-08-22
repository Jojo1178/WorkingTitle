#include "Resource.h"

#include <ostream>

#include "ResourceType.h"

namespace wot {
    Resource::Resource() {
        resourceType = ResourceType::NONE; 
        rawPath = "";

        name = "";
        description = "";

        loaded = false;
    }

    Resource::Resource(const Resource & resource){
        resourceType = resource.resourceType;
        rawPath = resource.rawPath; 

        name = resource.name;
        description = resource.description;

        loaded = resource.loaded;
    }

    Resource::~Resource() {}

    Resource & Resource::operator=(const Resource & resource) {
        resourceType = resource.resourceType;
        rawPath = resource.rawPath; 

        name = resource.name;
        description = resource.description;

        loaded = resource.loaded;

        return *this;
    }

    bool Resource::load() {return true;}
    bool Resource::free() {return true;}

    int Resource::construct(const std::string & rawPath) {
        return 0;
    }

    std::string Resource::toString() {
        return std::string("[" + ResourceTypeNames::names[resourceType] + "] " + name);
    }
} /* wot */
