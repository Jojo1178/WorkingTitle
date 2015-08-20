#include "ResourceType.h"

namespace wot {
    std::map<ResourceType, std::string> ResourceTypeNames::names = {
        {ResourceType::NONE, "NONE"},
        {ResourceType::TEXT, "TEXT"},
        {ResourceType::IMAGE, "IMAGE"},
        {ResourceType::BUTTON, "BUTTON"},
        {ResourceType::SCENE, "SCENE"},
    };
} /* wot */
