#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace wot {
    class Coordinates {
        public:
            int x;
	    int y;
	    
	    Coordinates();
	    Coordinates(int valX, int valY);
	    Coordinates(const Coordinates& valCoordinates);
            Coordinates isoToTwoD(Coordinates iso, int tileWHalf, int tileHHalf, int screenWidth);
            Coordinates twoDToIso(Coordinates twoD, int tileWHalf, int tileHHalf, int tileNbHalf);
	    Coordinates &operator=(const Coordinates&);
    };

    bool operator>(Coordinates const&,Coordinates const&);
    bool operator<(Coordinates const&,Coordinates const&);
    bool operator==(Coordinates const&,Coordinates const&);
} /* wot */

#endif /* __COORDINATES_H__ */
