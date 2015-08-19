#include "Coordinates.h"

#include <iostream>
#include <tuple>

namespace wot {
    Coordinates::Coordinates(void) {
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

    Coordinates Coordinates::isoToTwoD(Coordinates iso, int tileWHalf, int tileHHalf, int screenWidth){
        Coordinates twoD = Coordinates();
        twoD.x = (iso.x - iso.y) * tileWHalf + screenWidth ;
        twoD.y = (iso.x + iso.y) * tileHHalf;
        return(twoD);
    }

    Coordinates Coordinates::twoDToIso(Coordinates twoD, int tileWHalf, int tileHHalf, int tileNbHalf){
        Coordinates iso = Coordinates();
	iso.x = ((twoD.x / tileWHalf + twoD.y / tileHHalf) /2) - tileNbHalf;
	iso.y = ((twoD.y / (tileHHalf) -(twoD.x / tileWHalf)) /2) + tileNbHalf;
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

    void Coordinates::operator=(Coordinates val){
	x = val.x;
	y = val.y;
    }

    bool operator==(Coordinates const& a,Coordinates const& b){
	return (a.x == b.x && a.y == b.y);
    }
    
} /* wot */
