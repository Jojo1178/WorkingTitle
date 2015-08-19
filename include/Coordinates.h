#ifndef __COORDINATES_H__
#define __COORDINATES_H__

namespace wot {
    class Coordinates {
        public:
            int x;
	    int y;
	    
	    Coordinates(void);
	    Coordinates(int, int);
	    Coordinates(const Coordinates&);
            Coordinates isoToTwoD(Coordinates, int, int, int);
            Coordinates twoDToIso(Coordinates, int, int, int);
	    void operator=(Coordinates);
    };

    bool operator>(Coordinates const&,Coordinates const&);
    bool operator<(Coordinates const&,Coordinates const&);
    bool operator==(Coordinates const&,Coordinates const&);
} /* wot */

#endif /* __COORDINATES_H__ */
