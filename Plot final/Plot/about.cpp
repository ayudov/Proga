#include "about.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    setWindowTitle("Інфо");
    setFixedSize(552, 360);
}

AboutWindow::~AboutWindow()
{
    delete ui;
}

void AboutWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
