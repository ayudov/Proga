#ifndef SMALLENEMY_H
#define SMALLENEMY_H

#include <QGraphicsItem>
#include <QObject>
#include <stdlib.h>

class SmallEnemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    SmallEnemy();
public slots:
    void move();
private:
    int direction;
    int random_number_direction  = rand();
};

#endif // SMALLENEMY_H
