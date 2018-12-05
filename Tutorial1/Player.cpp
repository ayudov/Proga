#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Bullet.h"
#include "Enemy.h"
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
    }

}

void Player::spawnsmall(int x, int y){
    //create an small enemy
    SmallEnemy * smallenemy = new SmallEnemy();
    smallenemy->setPos(x, y);
    scene()->addItem(smallenemy);
}

void Player::spawn(){
    //create an enemy
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

