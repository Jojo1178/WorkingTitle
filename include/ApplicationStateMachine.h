#ifndef __APPLICATIONSTATEMACHINE_H__
#define __APPLICATIONSTATEMACHINE_H__

#include "ApplicationState.h"

extern "C" {
#include <SDL.h>
#include <SDL_image.h>
}

#include <iostream>

namespace wot {
    class ApplicationState;
    class ApplicationStateMachine {
        protected:
            ApplicationState * state;

            static SDL_Window * window;
            static SDL_Surface * screen;
            static SDL_Renderer * renderer;

            bool errorFlag;
    
        public:
            static SDL_Window * getWindow();
            static SDL_Surface * getScreen();

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
