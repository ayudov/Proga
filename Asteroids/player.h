#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
    void spawnsmalla(int x, int y);
    //void spawnsmallb(int x, int y);
private:
    QMediaPlayer * bulletsound = new QMediaPlayer();

};



#endif // PLAYER_H
