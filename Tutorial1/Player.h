#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QObject>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawnsmall(int x, int y);
};



#endif // MYRECT_H
