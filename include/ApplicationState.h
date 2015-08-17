#ifndef __APPLICATIONSTATE_H__
#define __APPLICATIONSTATE_H__

#include "ApplicationStateMachine.h"

extern "C" {
#include <SDL.h>
}

namespace wot {
    class ApplicationStateMachine;
    class ApplicationState {
        protected:
            ApplicationStateMachine * machine;
        public:
            ApplicationState (ApplicationStateMachine * _machine);
            ApplicationState (const ApplicationState& _state);
            virtual ~ApplicationState ();
    
            ApplicationState &operator=(const ApplicationState& _state);

            virtual void controlLoop(SDL_Event * e);
            virtual void displayLoop(SDL_Surface * surface);
    };
} /* wot */

#endif /* __APPLICATIONSTATE_H__ */
