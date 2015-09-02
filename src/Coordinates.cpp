#include "Coordinates.h"
#include <math.h>

/*
//Cartesian to isometric:
 
isoX = cartX - cartY;
isoY = (cartX + cartY) / 2;
	
//Isometric to Cartesian:
 
cartX = (2 * isoY + isoX) / 2;
cartY = (2 * isoY - isoX) / 2;
*/

namespace wot {
    Coordinates::Coordinates() {
        x = 0;
	y = 0;
    }

    Coordinates::Coordinates(int valX, int valY) {
        x = valX;
	y = valY;
    }

    Coordinates::Coordinates(const Coordinates& valCoordinates){
	x = valCoordinates.x;
	y = valCoordinates.y;
    }

    Coordinates Coordinates::isoToScreen(Coordinates iso, int tileW, int tileH, int screenWidth){
        Coordinates screen = Coordinates();
        screen.x = (screenWidth/2) - (iso.y * tileW/2) + (iso.x * tileW/2) - (tileW/2);
        screen.y = (iso.y * tileH/2) + (iso.x * tileH/2);
//IsoDeltaX = (MapDeltaX – MapDeltaY)
//IsoDeltaY = (MapDeltaY + MapDeltaX) / 2
        return(screen);
    }

    Coordinates Coordinates::screenToIso(Coordinates screen, int tileW, int tileH, int screenWidth, int screenHeight){
        Coordinates iso = Coordinates();
//X0 = ScreenX – (OriginX – IsoDeltaX)
//Y0 = ScreenY – (OriginY – IsoDeltaY)
        int X0 = screen.x - ((screenWidth/2) - 0);
        int Y0 = screen.y - (0 - 0);

//X = Y0 + (X0 / 2)
//Y = Y0 – (X0 / 2)
        int X = Y0 + (X0 / 2);
        int Y = Y0 - (X0 / 2);
	//iso.x = ((screen.x / tileWHalf + screen.y / tileHHalf) /2) - screenWidth/(tileWHalf*4);
	//iso.y = ((screen.y / tileHHalf -(screen.x / tileWHalf)) /2) + screenHeight/(tileHHalf*4);
        iso.x = X / tileH;
        iso.y = Y / tileH;
//MapDeltaX = X \ TileDepth
//MapDeltaY = Y \ TileDepth
        return(iso);
    }

    bool operator>(Coordinates const& a,Coordinates const& b){
	if((a.y > b.y) || (a.y == b.y && a.x >= b.x))
		return true;
	else
		return false;
	//return std::tie(a.x,a.y) > std::tie(b.x,b.y);
    }

    bool operator<(Coordinates const& a,Coordinates const& b){
	if((a.y < b.y) || (a.y == b.y && a.x <= b.x))
		return true;
	else
		return false;
	//return std::tie(a.x,a.y) < std::tie(b.x,b.y);
    }

    Coordinates & Coordinates::operator=(const Coordinates& val){
	x = val.x;
	y = val.y;
        return *this;
    }

    bool operator==(Coordinates const& a,Coordinates const& b){
	return (a.x == b.x && a.y == b.y);
    }
    
} /* wot */
