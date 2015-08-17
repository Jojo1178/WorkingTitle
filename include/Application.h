#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "ApplicationStateMachine.h"

namespace wot {
    class Application : public ApplicationStateMachine {
        public:
            Application (void);
            ~Application ();
    };
} /* wot */

#endif /* __APPLICATION_H__ */
