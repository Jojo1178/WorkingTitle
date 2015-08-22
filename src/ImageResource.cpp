#include "ImageResource.h"

#include <fstream>

#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"
#include "SDLHelpers.h"

namespace wot {
    ImageResource::ImageResource() : TextResource() {
        resourceType = ResourceType::IMAGE;
        bitmapPath = "";
        bitmap = NULL; 
    }

    ImageResource::ImageResource(const ImageResource & imageResource) : TextResource(imageResource) {
        bitmapPath = imageResource.bitmapPath;
        bitmap = imageResource.bitmap;
    }

    ImageResource::~ImageResource() {
        if (loaded)
            if (bitmap != NULL)
                SDL_FreeSurface(bitmap);
    }

    ImageResource & ImageResource::operator=(const ImageResource & imageResources) {
        resourceType = imageResources.resourceType;
        rawPath = imageResources.rawPath; 

        name = imageResources.name;
        description = imageResources.description;

        loaded = imageResources.loaded;

        bitmapPath = imageResources.bitmapPath;
        bitmap = imageResources.bitmap;

        return *this;
    }

    bool ImageResource::load() {
        if (!loaded) {
            if ((bitmap = SDLHelpers::loadBitmap(bitmapPath)) != NULL)
                loaded = true;
        }
        return loaded;
    }

    bool ImageResource::free() {
        if (loaded) {
            if (bitmap == NULL)
                SDL_FreeSurface(bitmap);
            loaded = false;
        }
        return loaded;
    }

    int ImageResource::construct(const std::string & rawPath) {
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
                case 3:
                    bitmapPath = ApplicationPreferencesManager::getStringPreference("resources_path", DEFAULT_RAW_RESOURCES_PATH) + line;
                    std::ifstream infile(bitmapPath);
                    if (!infile.good())
                        return 0;
                    break;
            }
            ++il;
        }
        if (il < 3) return 0;
        return 1;
    }

    std::string ImageResource::toString() {
        return std::string("[" + ResourceTypeNames::names[resourceType] + "] " + name + 
            ":" + bitmapPath);
    }

    SDL_Surface * ImageResource::getBitmap() {
        return bitmap;
    }
} /* wot */
