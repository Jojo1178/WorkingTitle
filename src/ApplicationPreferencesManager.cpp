#include "ApplicationPreferencesManager.h"

namespace wot {
    ApplicationPreferencesManager::ApplicationPreferencesManager() {}
    ApplicationPreferencesManager::~ApplicationPreferencesManager() {}

    void ApplicationPreferencesManager::FeedPreferences(std::string preferenceFilePath) {

    }

    void ApplicationPreferencesManager::FeedPreferences(int argc, char* argv[]) {

    }

    bool ApplicationPreferencesManager::getBooleanPreference(std::string & key, bool def) {
        return def;
    }

    int  ApplicationPreferencesManager::getIntegerPreference(std::string & key, int def) {
        return def;
    }

    std::string ApplicationPreferencesManager::getStringPreference(std::string & key, std::string def) {
        return def;
    }
} /* wot */
