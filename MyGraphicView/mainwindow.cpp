#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Инициализируем виджет с графикой */
    myPicture   = new MyGraphicView();
    /* и добавляем его на слой */
    ui->graphicLayout->addWidget(myPicture);
}

MainWindow::~MainWindow()
{
    delete ui;
}
