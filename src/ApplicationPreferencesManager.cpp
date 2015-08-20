#include "ApplicationPreferencesManager.h"

#include "DefaultValues.h"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>

namespace wot {
    std::map<std::string, int> ApplicationPreferencesManager::integerPreferences;
    std::map<std::string, std::string> ApplicationPreferencesManager::stringPreferences;

    ApplicationPreferencesManager::ApplicationPreferencesManager() {}
    ApplicationPreferencesManager::~ApplicationPreferencesManager() {}

    void ApplicationPreferencesManager::feedPreferences(std::string preferenceFilePath) {
        std::string line;
        std::ifstream infile(preferenceFilePath);

        while (std::getline(infile, line)) {
            bool conversion_error = false;
            int intvalue = 0;
            std::string key, value;
            std::stringstream ss(line);
            ss >> key;
            ss >> std::ws;
            std::getline(ss, value);
            
            try {
                intvalue = std::stoi(value);
            } catch (const std::invalid_argument& e) {
                conversion_error = true;
            }

            if (conversion_error)
                stringPreferences[key] = value;
            else
                integerPreferences[key] = intvalue;
        }
    }

    void ApplicationPreferencesManager::feedPreferences(int argc, char* argv[]) {
        if (argc > 1) {
            for (int i = 1; i < argc; i++) {
                std::string param = argv[i];
                if (param[0] == '-') {
                    if (param[1] == '-') {
                        std::string param_content = param.substr(2);
                        int separator_index;
                        if (separator_index = param_content.find("=")) {
                            std::string key = param_content.substr(0, separator_index);
                            std::string value = param_content.substr(separator_index+1);

                            bool conversion_error = false;
                            int intvalue = 0;
                            
                            try {
                                intvalue = std::stoi(value);
                            } catch (const std::invalid_argument& e) {
                                conversion_error = true;
                            }

                            if (conversion_error)
                                stringPreferences[key] = value;
                            else
                                integerPreferences[key] = intvalue;
                        }
                    }
                } else std::cerr << "Unrecognized parameter: " << param << std::endl;
            }
        }
    }

    void ApplicationPreferencesManager::clearPreferences() {
        integerPreferences.clear();
        stringPreferences.clear();
    }

    void ApplicationPreferencesManager::printPreferences() {
        std::cout << "INTEGER PREFERENCES:" << std::endl;
        for (auto iit = integerPreferences.begin(); iit!=integerPreferences.end(); ++iit) {
            std::cout << "KEY: " << iit->first << " VALUE:" << iit->second << std::endl;
        }

        std::cout << "STRING PREFERENCES:" << std::endl;
        for (auto sit = stringPreferences.begin(); sit!=stringPreferences.end(); ++sit) {
            std::cout << "KEY: " << sit->first << " VALUE:" << sit->second << std::endl;
        }
    }

    int  ApplicationPreferencesManager::getIntegerPreference(std::string key, int def) {
        int ret;
        try {
            ret = integerPreferences.at(key); 
        } catch (std::out_of_range& e) {
            return def;
        }
        return ret;
    }

    std::string ApplicationPreferencesManager::getStringPreference(std::string key, std::string def) {
        std::string ret;
        try {
            ret = stringPreferences.at(key); 
        } catch (std::out_of_range& e) {
            return def;
        }
        return ret;
    }
} /* wot */
