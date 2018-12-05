#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "SmallEnemy.h"
#include "game.h"
#include <typeinfo>
#include "Player.h"
//#include <QDebug>

extern Game * game; // there is an external, global obj. called game

Bullet::Bullet(){
    // drew the rect
    setRect(0,0,10,20);

    // connect
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));

    timer->start(10);
}

void Bullet::move(){
    // move bullet up
    setPos(x(), y()-5);
    if (pos().y() + rect().height() < 0){
    scene()->removeItem(this);
    delete this;
    }

    //if bullet collides with enemy, destroy both & create two smalls
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; i++){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //remove them both
            delete colliding_items[i];
            delete this;

            //creating smaller enemies
            game->player->spawnsmall( pos().x()-10, pos().y() );
            //game->player->spawnsmall( pos().x()+10, pos().y() );

         return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(SmallEnemy)){
            // increase the score
            game->score->increase();
            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //remove them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }
}

