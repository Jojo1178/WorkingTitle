#include "ScreenResource.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

namespace wot {
    ScreenResource::ScreenResource() : TextResource() {}

    ScreenResource::ScreenResource(const ScreenResource & screenResource) : TextResource(screenResource) {
        content = screenResource.content;
    }

    ScreenResource::~ScreenResource() {}

    ScreenResource & ScreenResource::operator=(const ScreenResource & screenResource) {

    }

    bool ScreenResource::load() {return true;}
    bool ScreenResource::free() {return true;}

    int ScreenResource::construct(const std::string & rawPath) {
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
                default:
                    std::stringstream ss(line);
                    break;
            }
            ++il;
        }
        if (il < 2) return 0;
        return 1;
    }

    std::string ScreenResource::toString() {
        return std::string("[" + ResourceTypeNames::names[resourceType] + "] " + name + 
            ":(" + std::to_string(content.size()) + ")");
    }
} /* wot */
