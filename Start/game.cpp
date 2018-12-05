#include "game.h"

Game& Game::Insatance(){
    static Game tsi;
    return tsi;
};

/*void Game::run(){
    g.show();
}*/
