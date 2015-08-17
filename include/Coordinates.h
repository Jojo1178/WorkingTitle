#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace wot {
    class Coordinates {
        public:
            int x;
	    int y;
	    
	    Coordinates(void);
	    Coordinates(int valX, int valY);
	    void operator=(Coordinates val);
    };

    bool operator>(Coordinates const& a,Coordinates const& b);
    bool operator<(Coordinates const& a,Coordinates const& b);
    bool operator==(Coordinates const& a,Coordinates const& b);
} /* wot */

#endif /* __COORDINATES_H__ */
