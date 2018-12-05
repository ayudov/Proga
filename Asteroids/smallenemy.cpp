#include "smallEnemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include "asteroids.h"
//#include <QDebug>

extern Game * game;

SmallEnemy::SmallEnemya(){
    //set  direction
    direction = 1;

    // drew the rect
    setRect(0,0,50,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(70);
}

SmallEnemy::SmallEnemyb(){
    //set  direction
    direction = 0;

    // drew the rect
    setRect(0,0,50,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(70);
}


/*SmallEnemy::SmallEnemy(){
    //set random direction
    if ( (random_number_direction % 2) == 0){
        direction = 0;
    }
    else { direction = 1; }

    // drew the rect
    setRect(0,0,50,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50);
}*/

void SmallEnemy::move(){
    // move enemy down
    if ( pos().x() < 0 && direction == 0){
            direction = 1;
        }
    else if ( pos().x() > 750 && direction == 1 ){
         direction = 0;
    }
    else if  (direction == 0 ){
        setPos(x()-5, y()+5);
    }
    else if  ( direction == 1 ){
        setPos(x()+5, y()+5);
    }

    //destroy enemy when it goes out of the screen
    if (pos().y() >800){
        //decrease health
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }
}


