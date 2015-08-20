#include "Resource.h"
#include "ResourceType.h"

namespace wot {
    Resource::Resource() {
        resourceType = ResourceType::NONE; 
        rawPath = "";

        name = "";
        description = "";
    }

    Resource::Resource(const Resource & resource){
        resourceType = resource.resourceType;
        rawPath = resource.rawPath; 

        name = resource.name;
        description = resource.description;
    }

    Resource::~Resource() {}

    Resource & Resource::operator=(const Resource & resource) {
        resourceType = resource.resourceType;
        rawPath = resource.rawPath; 

        name = resource.name;
        description = resource.description;

        return *this;
    }

    int Resource::construct(const std::string & rawPath) {
        return 0;
    }

    std::string Resource::toString() {
        return std::string("[" + ResourceTypeNames::names[resourceType] + "] " + name);
    }
} /* wot */
