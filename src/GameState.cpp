#include "GameState.h"

#include "Scene.h"
#include "Item.h"
#include "Coordinates.h"
#include "ApplicationPreferencesManager.h"
#include "DefaultValues.h"

#include <vector>

namespace wot {
    GameState::GameState(ApplicationStateMachine * _machine) : ApplicationState(_machine) {}
    GameState::GameState(const GameState& _state) : ApplicationState(_state) {}
    GameState::~GameState() {}

    GameState & GameState::operator=(const GameState& _state) {
        machine = _state.machine;        
        return *this;
    }

    void GameState::controlLoop(SDL_Event * e) {
        switch (e->type){
            case SDL_KEYDOWN:
                break;
            case SDL_KEYUP:
                break;
            case SDL_MOUSEMOTION:
                break;
            case SDL_MOUSEBUTTONDOWN:
                int x,y;
                if(SDL_BUTTON(SDL_GetMouseState(&x, &y)) == SDL_BUTTON_LEFT){
                    std::cout<<x<<","<<y<<std::endl;
                    Coordinates newCoor = Coordinates(x,y);
                    newCoor = newCoor.screenToIso(
                        newCoor,
                        ApplicationPreferencesManager::getIntegerPreference("tileWidth", DEFAULT_WIDTH),
                        ApplicationPreferencesManager::getIntegerPreference("tileHeight", DEFAULT_HEIGHT)
                    );
                    std::cout<<newCoor.x<<","<<newCoor.y<<"\n"<<std::endl;
                    int isoDeltaX = ApplicationPreferencesManager::getIntegerPreference("MapDeltaX",0) - ApplicationPreferencesManager::getIntegerPreference("MapDeltaY",0);
                    int isoDeltaY = (ApplicationPreferencesManager::getIntegerPreference("MapDeltaY",0) + ApplicationPreferencesManager::getIntegerPreference("MapDeltaX",0))/2;
                    ApplicationPreferencesManager::setIntegerPreference("IsoDeltaX",isoDeltaX);
                    ApplicationPreferencesManager::setIntegerPreference("IsoDeltaY",isoDeltaY);
                    std::cout<<"Delta"<<std::endl;
                    std::cout<<ApplicationPreferencesManager::getIntegerPreference("MapDeltaX",0)<<","<<ApplicationPreferencesManager::getIntegerPreference("MapDeltaY",0)<<std::endl;
                    std::cout<<ApplicationPreferencesManager::getIntegerPreference("IsoDeltaX",0)<<","<<ApplicationPreferencesManager::getIntegerPreference("IsoDeltaY",0)<<std::endl;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                break;
            default:
                break;
        }
    }

    void GameState::displayLoop(SDL_Surface * surface) {
        Item item1 = Item(1,"Obj1",false,1,Coordinates(0,0),Resource());
        Item item01 = Item(6,"Obj01",false,1,Coordinates(0,1),Resource());
        Item item10 = Item(7,"Obj10",false,1,Coordinates(1,0),Resource());
        Item item11 = Item(8,"Obj11",false,1,Coordinates(1,1),Resource());
        Item item02 = Item(9,"Obj02",false,1,Coordinates(0,2),Resource());
        Item item20 = Item(10,"Obj20",false,1,Coordinates(2,0),Resource());
        Item item22 = Item(11,"Obj22",false,1,Coordinates(2,2),Resource());
        Item item2 = Item(2,"Obj2",false,1,Coordinates(9,9),Resource());
        Item item3 = Item(3,"Obj3",false,1,Coordinates(9,0),Resource());
        Item item4 = Item(4,"Obj4",false,1,Coordinates(0,9),Resource());
        Item item5 = Item(5,"Obj5",false,1,Coordinates(4,4),Resource());
        std::vector<Item> items;
        Scene mainScene = Scene(1,items ,LocalPlayer());
        mainScene.addItem(item1);
        mainScene.addItem(item2);
        mainScene.addItem(item3);
        mainScene.addItem(item4);
        mainScene.addItem(item5);
        mainScene.addItem(item10);
        mainScene.addItem(item01);
        mainScene.addItem(item11);
        mainScene.addItem(item20);
        mainScene.addItem(item02);
        mainScene.addItem(item22);
        mainScene.render(surface);
    }
} /* wot */
