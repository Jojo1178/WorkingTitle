#include "ApplicationStateMachine.h"

#include "DefaultValues.h"

#include "ApplicationPreferencesManager.h"
#include "InitState.h"

namespace wot {
    ApplicationStateMachine::ApplicationStateMachine() {
        errorFlag = false;
    }

    ApplicationStateMachine::ApplicationStateMachine(const ApplicationStateMachine& _machine) {
        state = _machine.state;

        window = _machine.window;
        screen = _machine.screen;

        errorFlag = _machine.errorFlag;
    }

    ApplicationStateMachine::~ApplicationStateMachine() {

    }

    ApplicationStateMachine & ApplicationStateMachine::operator=(const ApplicationStateMachine& _machine) {
        state = _machine.state;
        return *this;
    }

    void ApplicationStateMachine::PreInit (int argc, char* argv[]) {
        ApplicationPreferencesManager::feedPreferences(DEFAULT_CONFIGFILE);

        ApplicationPreferencesManager::printPreferences();
    }

    void ApplicationStateMachine::Init (void) {
        if (errorFlag) return;
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "Unable to initialize SDL: " << SDL_GetError() << std::endl;
            errorFlag = true;
            return;
        }
        
        window = SDL_CreateWindow(
                "Working Title", 
                SDL_WINDOWPOS_UNDEFINED, 
                SDL_WINDOWPOS_UNDEFINED, 
                800, 600, 
                SDL_WINDOW_SHOWN);

        screen = SDL_GetWindowSurface(window);

        // Set the StateMachine's initial state
        state = new InitState(this);
    }

    void ApplicationStateMachine::Run (void) {
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
        SDL_DestroyWindow(window);
        window = NULL;
        SDL_FreeSurface(screen);
        screen = NULL;
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
