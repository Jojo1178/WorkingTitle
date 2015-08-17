#ifndef __APPLICATIONSTATEMACHINE_H__
#define __APPLICATIONSTATEMACHINE_H__

#include "ApplicationState.h"

extern "C" {
#include <SDL.h>
}

#include <iostream>

namespace wot {
    class ApplicationState;
    class ApplicationStateMachine {
        protected:
            ApplicationState * state;

            SDL_Window * window = NULL;
            SDL_Surface * screen = NULL;

            bool errorFlag;
    
        public:
            ApplicationStateMachine ();
            ApplicationStateMachine (const ApplicationStateMachine& _machine);
            virtual ~ApplicationStateMachine ();
    
            ApplicationStateMachine &operator=(const ApplicationStateMachine& _machine);

            void PreInit (int argc, char* argv[]);
            void Init (void);
            void Run (void);
            int Close (void);

            int Start (int argc, char* argv[]);

            void changeState(ApplicationState * _state);
    };
} /* wot */

#endif /* __APPLICATIONSTATEMACHINE_H__ */
