#include "TextResource.h"

#include <fstream>
#include <string>

#include "ResourceType.h"

namespace wot {
    TextResource::TextResource() : Resource() {
        resourceType = ResourceType::TEXT;
    }

    TextResource::TextResource(const TextResource & textResource) : Resource(textResource) {}

    TextResource::~TextResource() {}

    TextResource & TextResource::operator=(const TextResource & textResource) {
        resourceType = textResource.resourceType;
        rawPath = textResource.rawPath; 

        name = textResource.name;
        description = textResource.description;

        loaded = textResource.loaded;

        return *this;
    }

    bool TextResource::load() {return true;}
    bool TextResource::free() {return true;}

    int TextResource::construct(const std::string & rawPath) {
        std::string line;
        std::ifstream infile(rawPath);
        int il = 0;
        while (std::getline(infile, line)) {
            switch (il) {
                case 1:
                    /* retrieving the name */
                    name = line;
                    break;
                case 2:
                    /* retrieving the text body */
                    description = line;
                    break;
            }
            ++il;
        }
        if (il < 2) return 0;
        return 1;
    }
} /* wot */
