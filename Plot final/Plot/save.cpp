#include "save.h"
#include "ui_savewindow.h"

SaveWindow::SaveWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::SaveWindow)
{
    ui->setupUi(this);
    setWindowTitle("Save As");
}

SaveWindow::~SaveWindow()
{
    delete ui;
}

void SaveWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
