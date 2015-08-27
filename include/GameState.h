#ifndef __GAMESTATE_H__
#define __GAMESTATE_H__

#include "ApplicationState.h"
#include "ApplicationStateMachine.h"

extern "C" {
#include <SDL.h>
}

namespace wot {
    class GameState : public ApplicationState {
        public:
            GameState (ApplicationStateMachine * _machine);
            GameState (const GameState & _state);
            virtual ~GameState ();
    
            GameState &operator=(const GameState & _state);

            virtual void controlLoop(SDL_Event* e);
            virtual void displayLoop(SDL_Surface* surface);
    };
} /* wot */

#endif /* __GAMESTATE_H__ */
