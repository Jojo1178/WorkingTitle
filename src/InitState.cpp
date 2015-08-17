#include "InitState.h"

namespace wot {
    InitState::InitState(ApplicationStateMachine * _machine) : ApplicationState(_machine) {}
    InitState::InitState(const InitState& _state) : ApplicationState(_state) {}
    InitState::~InitState() {}

    InitState & InitState::operator=(const InitState& _state) {
        machine = _state.machine;        
        return *this;
    }

    void InitState::controlLoop(SDL_Event * e) {

    }

    void InitState::displayLoop(SDL_Surface * surface) {

    }

} /* wot */
