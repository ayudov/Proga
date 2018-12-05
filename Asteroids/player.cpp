#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "SmallEnemy.h"

#include <QDebug>

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-30,y());
    }
    else if(event->key() == Qt::Key_Right){
        if (pos().x() + 100 < 800)
        setPos(x()+30,y());
    }
    /*else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }*/
    else if(event->key()==Qt::Key_Space){
        //create a bullet
        Bullet * bullet  = new Bullet();
        bullet->setPos(x()+45, y()+20);
        scene()->addItem(bullet);

        // play bullet sound
        bulletsound->setMedia(QUrl("qrc:/sounds/gun2.mp3"));
        bulletsound->play();
    }
}

void Player::spawnsmalla(int x, int y){
    //create an small enemy
    SmallEnemy * smallenemya = new SmallEnemy();
    smallenemya->SmallEnemya();
    smallenemya->setPos(x+30, y);
    scene()->addItem(smallenemya);

    SmallEnemy * smallenemyb = new SmallEnemy();
    smallenemyb->SmallEnemyb();
    smallenemyb->setPos(x-30, y);
    scene()->addItem(smallenemyb);
    // qDebug() << "Passed (spawnsmalla)";
}

/*void Player::spawnsmallb(int x, int y){
    //create an small enemy
    SmallEnemy * smallenemy = new SmallEnemy();
    qDebug() << "Passed (SmallEnemy * smallenemy = new SmallEnemy())";
    smallenemy->setPos(x+30, y);
    qDebug() << "Passed (smallenemy->setPos(x+30, y))";
    scene()->addItem(smallenemy);
    qDebug() << "Passed (scene()->addItem(smallenemy))";
    qDebug() << "Passed (spawnsmallb)";
}*/

void Player::spawn(){
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

