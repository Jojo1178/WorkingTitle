#include "Resource.h"

namespace wot {
    Resource::Resource(void) {
        resourceType = "";
        imagePath = "";
        configPath = "";
    }

    Resource::Resource(std::string valResourceType, std::string valImagePath, std::string valConfigPath) {
        resourceType = valResourceType;
        imagePath = valImagePath;
        configPath = valConfigPath;
    }
    
} /* wot */
