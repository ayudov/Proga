#include "gamewidget.h"
#include <QTime>
#include <QTimer>
#include <QWidget>

GameWidget::GameWidget(QWidget *parent): QWidget(parent)

{
	setFixedSize(1360,765);
    pos = 0;
    timer = new QTimer;
    QObject::connect(timer, SIGNAL(timeout()), this, SLOT(wigetTimer()));
	timer->setInterval(5);
	timer->start();
}

void GameWidget::widgetTimer()
{
    if(pos <= 1219)
	{
        pos++;
	}
	else
	{
		timer->stop();
	}
	update();
}

void GameWidget::paintEvent(QPaintEvent*)
{
    QPixmap pictureBack(":/res/shutterstock_298536926-pic905-895x505-18882.jpg");
    QPixmap pictureFront(":/res/40_tn2.jpg");
	QPainter paint(this);
	paint.drawPixmap(0, 0, pictureBack);
    paint.drawPixmap(pos, 684, pictureFront);
}

GameWidget::~GameWidget() {}
