#ifndef SMALLENEMY_H
#define SMALLENEMY_H

#include <QGraphicsItem>
#include <QObject>
#include <stdlib.h>

class SmallEnemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    SmallEnemya();
    SmallEnemyb();
public slots:
    void move();
    //void mover();
private:
    int direction;
    int random_number_direction  = rand();
};

#endif // SMALLENEMY_H
