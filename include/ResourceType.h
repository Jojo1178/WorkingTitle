#ifndef __RESOURCETYPE_H__
#define __RESOURCETYPE_H__

#include <map>
#include <string>

namespace wot {
    enum class ResourceType {
        NONE,
        TEXT,
        IMAGE,
        BUTTON,
        SCREEN,
        SCENE
    };

    class ResourceTypeNames {
        public:
            static std::map<ResourceType, std::string> names;
    };
} /* wot */

#endif /* __RESOURCETYPE_H__ */
