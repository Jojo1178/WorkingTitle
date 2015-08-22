#include "ResourcesManager.h"

#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"
#include "ImageResource.h"
#include "TextResource.h"

#include <stdexcept>
#include <iostream>

extern "C" {
#include <fnmatch.h>
#include <libgen.h>
#include <ftw.h>
}

namespace wot {
    static const char * ffilter = DEFAULT_RAW_RESOURCES_FILE_EXTENTION;

    std::map<std::string, std::function<void(std::string)> > ResourcesManager::parseactions = {
        {"TEXT", [&](std::string fpath) {
                TextResource tr;
                if (tr.construct(fpath)) {
                    std::cout << "Loaded " << fpath << " as " << tr.toString() << std::endl;
                    resources[ResourceType::TEXT][tr.name] = tr;
                }

            }
        }, 
        {"IMAGE", [&](std::string fpath) {
                ImageResource ir;
                if (ir.construct(fpath)) {
                    std::cout << "Loaded " << fpath << " as " << ir.toString() << std::endl;
                    resources[ResourceType::TEXT][ir.name] = ir;
                }
            }
        },
        {"BUTTON", [&](std::string fpath) {
            }
        }, 
        {"SPRITE", [&](std::string fpath) {
            }
        }, 
        {"SCENE", [&](std::string fpath) {
            }
        }, 
        {"SCREEN", [&](std::string fpath) {
                
            }
        }
    };

    std::string ResourcesManager::resourcePath = "";
    std::map<ResourceType, std::map<std::string, Resource> > ResourcesManager::resources;

    ResourcesManager::ResourcesManager() {}
    ResourcesManager::~ResourcesManager() {}

    int ftw_callback(const char *fpath, const struct stat *sb, int typeflag) {
        if (FTW_F == typeflag) {
            if (fnmatch(ffilter, basename((char*)fpath), FNM_CASEFOLD) == 0) {
                std::string line;
                std::ifstream infile(fpath);
                std::string filekey = "";

                if (std::getline(infile, line)) {
                    std::stringstream sskf(line);
                    std::getline(sskf, filekey);
                }

                if (ResourcesManager::parseactions.count(filekey)) {
                    try {
                        ResourcesManager::parseactions.at(filekey)(fpath);
                    } catch (std::out_of_range& e) {
                        std::cerr << "Unknown resource type (" << filekey << 
                                ") in resource file " << fpath << std::endl;
                    }
                }
            }
        }
        return 0;
    }


    void ResourcesManager::feedResources(std::string resourcePath) {
        ResourcesManager::resourcePath = resourcePath;
        ftw(resourcePath.c_str(), ftw_callback, 5);
    }

    void ResourcesManager::clearResources() {
        resources.clear();
    }

    void ResourcesManager::printResources() {

    }
} /* wot */
