#include "gamewidget.h"
#include <QApplication>
#include "game.h"


int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    Game::Insatance();
    return a.exec();
}
