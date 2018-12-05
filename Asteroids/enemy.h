#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QObject>
#include <stdlib.h>

class Enemy: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Enemy();
public slots:
    void move();
private:
    int direction;
};


#endif // ENEMY_H
