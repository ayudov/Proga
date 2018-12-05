#ifndef GAME_H
#define GAME_H

#include "gamewidget.h"

class Game{

public:
    static Game& Insatance();
    void run();
private:
    Game();
    Game(const Game&);
    Game& operator = (const Game&);
    GameWidget g;
};

#endif // GAME_H
