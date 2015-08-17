#ifndef __INITSTATE_H__
#define __INITSTATE_H__

#include "ApplicationState.h"
#include "ApplicationStateMachine.h"

extern "C" {
#include <SDL.h>
}

namespace wot {
    class InitState : public ApplicationState {
        public:
            InitState (ApplicationStateMachine * _machine);
            InitState (const InitState& _state);
            virtual ~InitState ();
    
            InitState &operator=(const InitState& _state);

            virtual void controlLoop(SDL_Event* e);
            virtual void displayLoop(SDL_Surface* surface);
    };
} /* wot */

#endif /* __INITSTATE_H__ */
