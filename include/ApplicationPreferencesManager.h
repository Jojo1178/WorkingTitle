#ifndef __APPLICATIONPREFERENCESMANAGER_H__
#define __APPLICATIONPREFERENCESMANAGER_H__

#include <string>
#include <map>

namespace wot {
    class ApplicationPreferencesManager {
        public:
            static std::map<std::string, bool> booleanPreferences;
            static std::map<std::string, int> integerPreferences;
            static std::map<std::string, std::string> stringPreferences;
        
            ApplicationPreferencesManager ();
            virtual ~ApplicationPreferencesManager ();

            static void FeedPreferences(std::string preferenceFilePath);
            static void FeedPreferences(int argc, char* argv[]);

            static bool getBooleanPreference(std::string & key, bool def);
            static int getIntegerPreference(std::string & key, int def);
            static std::string getStringPreference(std::string & key, std::string def);
    };
} /* wot */

#endif /* __APPLICATIONPREFERENCESMANAGER_H__ */
