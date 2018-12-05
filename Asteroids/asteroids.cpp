//#include <QApplication>
#include "asteroids.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include "enemy.h"
#include <QMediaPlayer>

Game::Game(QWidget *parent){
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    setScene(scene);
    setHorizontalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setVerticalScrollBarPolicy((Qt::ScrollBarAlwaysOff));
    setFixedSize(800, 800);

    // create the player
    player = new Player();
    player->setRect(0,0,100,100);
    player->setPos(400,700);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x()+680, health->y());
    scene->addItem(health);

    //spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000);

    // play background musik
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/mix5.mp3"));
    music->play();

    show();
}
