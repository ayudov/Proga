#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "enemy.h"
#include "smallenemy.h"
#include "asteroids.h"
#include <typeinfo>
#include "player.h"
#include <QDebug>

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
            game->player->spawnsmalla( pos().x(), pos().y() );
           // qDebug() << "Passed (game->player->spawnsmalla)";
           /* game->player->spawnsmallb( pos().x(), pos().y() );
            qDebug() << "Passed (game->player->spawnsmallb)";*/



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

