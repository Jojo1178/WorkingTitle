#include "ButtonResource.h"

namespace wot {
    ButtonResource::ButtonResource() : ImageResource() {}

    ButtonResource::ButtonResource(const ButtonResource & buttonResource) : ImageResource(buttonResource) {}

    ButtonResource::~ButtonResource() {
        free();
    }

    ButtonResource & ButtonResource::operator=(const ButtonResource & buttonResource) {
        resourceType = buttonResource.resourceType;
        rawPath = buttonResource.rawPath; 

        name = buttonResource.name;
        description = buttonResource.description;

        loaded = buttonResource.loaded;

        bitmapPath = buttonResource.bitmapPath;
        bitmap = buttonResource.bitmap;

        return *this;
    }

    bool ButtonResource::load() {
        return loaded; 
    }

    bool ButtonResource::free() {
        return loaded; 
    }

    int ButtonResource::construct(const std::string & rawPath) {
        return 1;
    }

} /* wot */
