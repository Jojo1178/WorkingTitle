#include "Coordinates.h"
#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"
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

    Coordinates Coordinates::isoToScreen(Coordinates iso, int tileW, int tileH){
        Coordinates screen = Coordinates();
        screen.x = ApplicationPreferencesManager::getIntegerPreference("OriginX",0) - (iso.y * tileW/2) + (iso.x * tileW/2) - (tileW/2);
        screen.y = ApplicationPreferencesManager::getIntegerPreference("OriginY",0) + (iso.y * tileH/2) + (iso.x * tileH/2);

        int isoDeltaX = ApplicationPreferencesManager::getIntegerPreference("MapDeltaX",0) - ApplicationPreferencesManager::getIntegerPreference("MapDeltaY",0);
        int isoDeltaY = (ApplicationPreferencesManager::getIntegerPreference("MapDeltaY",0) + ApplicationPreferencesManager::getIntegerPreference("MapDeltaX",0))/2;

        ApplicationPreferencesManager::setIntegerPreference("IsoDeltaX",isoDeltaX);
        ApplicationPreferencesManager::setIntegerPreference("IsoDeltaY",isoDeltaY);
        return(screen);
    }

    Coordinates Coordinates::screenToIso(Coordinates screen, int tileW, int tileH){
        Coordinates iso = Coordinates();

        int X0 = screen.x - (ApplicationPreferencesManager::getIntegerPreference("OriginX",0) - ApplicationPreferencesManager::getIntegerPreference("IsoDeltaX", 0));
        int Y0 = screen.y - (ApplicationPreferencesManager::getIntegerPreference("OriginY",0) - ApplicationPreferencesManager::getIntegerPreference("IsoDeltaY", 0));

        int X = Y0 + (X0 / 2);
        int Y = Y0 - (X0 / 2);

        iso.x = X / tileH;
        iso.y = Y / tileH;

        int centerX = ApplicationPreferencesManager::getIntegerPreference("width", DEFAULT_WIDTH)/2;
        int centerY = ApplicationPreferencesManager::getIntegerPreference("height", DEFAULT_WIDTH)/2;
        int oriX = ApplicationPreferencesManager::getIntegerPreference("OriginX", DEFAULT_WIDTH);
        int oriY = ApplicationPreferencesManager::getIntegerPreference("OriginY", DEFAULT_WIDTH);

        ApplicationPreferencesManager::setIntegerPreference("MapDeltaX",iso.x);
        ApplicationPreferencesManager::setIntegerPreference("MapDeltaY",iso.y);

        if(centerX > screenClamp.x)
            ApplicationPreferencesManager::setIntegerPreference("OriginX",oriX - (screen.x - centerX));
        else
            ApplicationPreferencesManager::setIntegerPreference("OriginX",oriX + (centerX - screen.x));
        if(centerY > screenClamp.y)
            ApplicationPreferencesManager::setIntegerPreference("OriginY",oriY + (centerY - screen.y));
        else
            ApplicationPreferencesManager::setIntegerPreference("OriginY",oriY - (screen.y - centerY));
        return(iso);
    }

    bool operator>(Coordinates const& a,Coordinates const& b){
	if((a.y > b.y) || (a.y == b.y && a.x >= b.x))
		return true;
	else
		return false;
    }

    bool operator<(Coordinates const& a,Coordinates const& b){
	if((a.y < b.y) || (a.y == b.y && a.x <= b.x))
		return true;
	else
		return false;
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
