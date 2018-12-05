#include "instruction.h"
#include "ui_instructionwindow.h"

InstructionWindow::InstructionWindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::InstructionWindow)
{
    ui->setupUi(this);
    setWindowTitle("Інструкція");
    setFixedSize(400, 322);
}

InstructionWindow::~InstructionWindow()
{
    delete ui;
}

void InstructionWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
