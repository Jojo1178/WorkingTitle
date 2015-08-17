#include "Resource.h"

namespace wot {
    Resource::Resource(void) {
        resourceType = "";
        imagePath = "";
        configPath = "";
    }

    Resource::Resource(const Resource& valResource){
	resourceType = valResource.resourceType;
        imagePath = valResource.imagePath;
        configPath = valResource.configPath;
    }

    Resource::Resource(std::string valResourceType, std::string valImagePath, std::string valConfigPath) {
        resourceType = valResourceType;
        imagePath = valImagePath;
        configPath = valConfigPath;
    }

    void Resource::operator=(Resource valResource){
	resourceType = valResource.resourceType;
        imagePath = valResource.imagePath;
        configPath = valResource.configPath;
    }
    
} /* wot */
