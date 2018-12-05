#include "health.h"
#include <QFont>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    //draw the text
    setPlainText(QString("Здоровье: ") + QString::number(health));
    setDefaultTextColor((Qt::red));
    setFont(QFont("times", 14));
}

void Health::decrease(){
    health--;
     setPlainText(QString("Здоровье: ") + QString::number(health));
}

int Health::getHealth(){
    return health;
}
