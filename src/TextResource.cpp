#include "TextResource.h"

#include "ResourceType.h"

#include <fstream>
#include <string>

namespace wot {
    TextResource::TextResource() : Resource() {}
    TextResource::TextResource(const TextResource & textResource) : Resource(textResource) {}
    TextResource::~TextResource() {}

    int TextResource::construct(const std::string & rawPath) {
        resourceType = ResourceType::TEXT;
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
