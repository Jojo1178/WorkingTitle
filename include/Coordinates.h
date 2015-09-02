#ifndef __COORDINATES_H__
#define __COORDINATES_H__

#include <iostream>

namespace wot {
    class Coordinates {
        public:
            int x;
	    int y;
	    
	    Coordinates();
	    Coordinates(int valX, int valY);
	    Coordinates(const Coordinates& valCoordinates);
            Coordinates isoToScreen(Coordinates iso, int tileW, int tileH, int screenWidth);
            Coordinates screenToIso(Coordinates screen, int tileW, int tileH, int screenWidth, int screenHeight);
	    Coordinates &operator=(const Coordinates&);
    };

    bool operator>(Coordinates const&,Coordinates const&);
    bool operator<(Coordinates const&,Coordinates const&);
    bool operator==(Coordinates const&,Coordinates const&);
} /* wot */

#endif /* __COORDINATES_H__ */
