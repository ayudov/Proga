#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QMainWindow>
#include <QWidget>
#include <QPainter>
#include <QTime>


class GameWidget : public QWidget{

    Q_OBJECT
public:
    explicit GameWidget(QWidget *parent = 0);
    ~GameWidget();

private:
    int pos;
    QTimer *timer;
    void paintEvent(QPaintEvent*);
private slots:
    void widgetTimer();
};

#endif // GAMEWIDGET_H
