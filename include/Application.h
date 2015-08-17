#ifndef __APPLICATION_H__
#define __APPLICATION_H__

namespace wot {
    class Application {
        private:
            /* data */
    
        public:
            Application (void);
            void PreInit (void);
            void Init (void);
            void Run (void);
            void Close (void);

            void Start (void);
    };
} /* wot */

#endif /* __APPLICATION_H__ */
