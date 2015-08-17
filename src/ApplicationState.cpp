#include "ApplicationState.h"

namespace wot {
    ApplicationState::ApplicationState (ApplicationStateMachine * _machine) {
        machine = _machine;
    }

    ApplicationState::ApplicationState (const ApplicationState& _state) {
        machine = _state.machine;
    }

    ApplicationState::~ApplicationState() {

    }
    
    ApplicationState & ApplicationState::operator=(const ApplicationState& _state) {
        machine = _state.machine;
        return *this;
    }

    void ApplicationState::controlLoop(SDL_Event * e) {

    }

    void ApplicationState::displayLoop(SDL_Surface * surface) {

    }
} /* wot */
