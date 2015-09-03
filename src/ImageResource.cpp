#include "ImageResource.h"

#include <cstdlib>
#include <fstream>

#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"
#include "SDLHelpers.h"

namespace wot {
    ImageResource::ImageResource() : TextResource() {
        resourceType = ResourceType::IMAGE;
        bitmapPath = "";
        bitmap = NULL; 

        originX = 0;
        originY = 0;
    }

    ImageResource::ImageResource(const ImageResource & imageResource) : TextResource(imageResource) {
        bitmapPath = imageResource.bitmapPath;
        bitmap = imageResource.bitmap;

        originX = imageResource.originX;
        originY = imageResource.originY;
    }

    ImageResource::~ImageResource() {
        free();
    }

    ImageResource & ImageResource::operator=(const ImageResource & imageResource) {
        resourceType = imageResource.resourceType;
        rawPath = imageResource.rawPath; 

        name = imageResource.name;
        description = imageResource.description;

        loaded = imageResource.loaded;

        bitmapPath = imageResource.bitmapPath;
        bitmap = imageResource.bitmap;

        originX = imageResource.originX;
        originY = imageResource.originY;

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
                case 3: {
                        bitmapPath = ApplicationPreferencesManager::getStringPreference("resources_path", DEFAULT_RAW_RESOURCES_PATH) + line;
                        std::ifstream infile(bitmapPath);
                        if (!infile.good())
                            return 0;
                        break;
                    }
                case 4: {
                    int originSeparator = line.find(",");
                    if (originSeparator!=std::string::npos) {
                        originX = std::stoi(line.substr(0, originSeparator));
                        originY = std::stoi(line.substr(originSeparator+1, line.size()));
                    }
                    break;
                }
            }
            ++il;
        }
        if (il < 4) return 0;
        return 1;
    }

    std::string ImageResource::toString() {
        return std::string("[" + ResourceTypeNames::names[resourceType] + "] " + name + 
            ":" + bitmapPath + " (" + std::to_string(originX) + ":" + std::to_string(originY) + ")");
    }

    SDL_Surface * ImageResource::getBitmap() {
        return bitmap;
    }

    std::pair<int, int> ImageResource::getOrigin() {
        return std::make_pair(originX, originY);
    }
} /* wot */
