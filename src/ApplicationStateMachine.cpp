#include "ApplicationStateMachine.h"

#include "ApplicationPreferencesManager.h"
#include "ResourcesManager.h"
#include "DefaultValues.h"
#include "InitState.h"

namespace wot {
    SDL_Window * ApplicationStateMachine::window = NULL;
    SDL_Surface * ApplicationStateMachine::screen = NULL;
    SDL_Renderer * ApplicationStateMachine::renderer = NULL;

    SDL_Window * ApplicationStateMachine::getWindow() {
        return window;
    }

    SDL_Surface * ApplicationStateMachine::getScreen() {
        return screen;
    }

    ApplicationStateMachine::ApplicationStateMachine() {
        errorFlag = false;
    }

    ApplicationStateMachine::ApplicationStateMachine(const ApplicationStateMachine& _machine) {
        state = _machine.state;

        window = _machine.window;
        screen = _machine.screen;
        renderer = _machine.renderer;

        errorFlag = _machine.errorFlag;
    }

    ApplicationStateMachine::~ApplicationStateMachine() {}

    ApplicationStateMachine & ApplicationStateMachine::operator=(const ApplicationStateMachine& _machine) {
        state = _machine.state;

        window = _machine.window;
        screen = _machine.screen;
        renderer = _machine.renderer;

        return *this;
    }

    void ApplicationStateMachine::PreInit (int argc, char* argv[]) {
        std::cout << "[*] PreInit" << std::endl;

        ApplicationPreferencesManager::feedPreferences(DEFAULT_CONFIGFILE);
        ApplicationPreferencesManager::feedPreferences(argc, argv);

        ResourcesManager::feedResources(ApplicationPreferencesManager::getStringPreference("raw_resources_path", DEFAULT_RAW_RESOURCES_PATH));
        ResourcesManager::printResources();
    }

    void ApplicationStateMachine::Init (void) {
        std::cout << "[*] Init" << std::endl;
        if (errorFlag) return;
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
            errorFlag = true;
            return;
        }

        window = SDL_CreateWindow(
            ApplicationPreferencesManager::getStringPreference("name", DEFAULT_NAME).c_str(),
            SDL_WINDOWPOS_UNDEFINED, 
            SDL_WINDOWPOS_UNDEFINED, 
            ApplicationPreferencesManager::getIntegerPreference("width", DEFAULT_WIDTH),
            ApplicationPreferencesManager::getIntegerPreference("height", DEFAULT_HEIGHT),
            SDL_WINDOW_SHOWN);

        int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF;
        if(!(IMG_Init(imgFlags) & imgFlags)) {
            errorFlag = true;
            return;
        } 

        screen = SDL_GetWindowSurface(window);

        renderer = SDL_CreateRenderer(window, -1, 0);

        // Set the StateMachine's initial state
        state = new InitState(this);
    }

    void ApplicationStateMachine::Run (void) {
        std::cout << "[*] Run" << std::endl;
        if (errorFlag) return;
        bool running = true;
        SDL_Event e;
        while (running) {
            while (SDL_PollEvent(&e) != 0) {
                if (e.type == SDL_QUIT) {
                    running = false;
                    break;
                }
                state->controlLoop(&e);
            }
            state->displayLoop(screen);
        }
    }

    int ApplicationStateMachine::Close (void) {
        std::cout << "[*] Close" << std::endl;

        SDL_FreeSurface(screen);
        SDL_DestroyWindow(window);
        SDL_Quit();

        if (errorFlag) return 1;
        return 0;
    }

    int ApplicationStateMachine::Start (int argc, char* argv[]) {
        PreInit(argc, argv);
        Init();
        Run();
        return Close();
    }

    void ApplicationStateMachine::changeState(ApplicationState * _state) {
        state = _state;
    }
} /* wot */
