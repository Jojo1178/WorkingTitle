#include "GameState.h"

namespace wot {
    GameState::GameState(ApplicationStateMachine * _machine) : ApplicationState(_machine) {}
    GameState::GameState(const GameState& _state) : ApplicationState(_state) {}
    GameState::~GameState() {}

    GameState & GameState::operator=(const GameState& _state) {
        machine = _state.machine;        
        return *this;
    }

    void GameState::controlLoop(SDL_Event * e) {

    }

    void GameState::displayLoop(SDL_Surface * surface) {

    }
} /* wot */
