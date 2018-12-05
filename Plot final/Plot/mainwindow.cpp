#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qmath.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(1037, 535);

    AWindow = new AboutWindow();
    connect(AWindow, &AboutWindow::firstWindow, this, &MainWindow::show);

    IWindow = new InstructionWindow();
    connect(IWindow, &InstructionWindow::firstWindow, this, &MainWindow::show);

    ui->plot->addGraph();
    ui->plot->xAxis->setRange(0, 10);
    ui->plot->yAxis->setRange(0, 10);
    ui->plot->xAxis->setLabel("x");
    ui->plot->yAxis->setLabel("y");

    ui->bx_a->setSingleStep(0.5);
    ui->bx_b->setSingleStep(0.5);
    ui->bx_c->setSingleStep(0.5);
    ui->bx_d->setSingleStep(0.5);
    ui->bx_e->setSingleStep(0.5);
    ui->bx_t->setSingleStep(0.5);
    ui->x_min->setSingleStep(0.5);
    ui->x_max->setSingleStep(0.5);
    ui->y_min->setSingleStep(0.5);
    ui->y_max->setSingleStep(0.5);
//
    ui->bx_a->setValue(1);
    ui->bx_b->setValue(1);
    ui->bx_c->setValue(0);
    ui->bx_d->setValue(1);
    ui->bx_e->setValue(0);
    ui->bx_t->setValue(2);
    ui->x_min->setValue(0);
    ui->x_max->setValue(10);
    ui->y_min->setValue(0);
    ui->y_max->setValue(10);
//
    ui->bx_a->setMaximum(99.90);
    ui->bx_b->setMaximum(99.90);
    ui->bx_c->setMaximum(99.90);
    ui->bx_d->setMaximum(99.90);
    ui->bx_e->setMaximum(99.90);
    ui->bx_t->setMaximum(99.90);
    ui->x_min->setMaximum(0);
    ui->x_max->setMaximum(99.90);
    ui->y_min->setMaximum(0);
    ui->y_max->setMaximum(99.90);
//
    ui->bx_a->setMinimum(-99.90);
    ui->bx_b->setMinimum(-99.90);
    ui->bx_c->setMinimum(-99.90);
    ui->bx_d->setMinimum(-99.90);
    ui->bx_e->setMinimum(-99.90);
    ui->bx_t->setMinimum(-99.90);
    ui->x_min->setMinimum(-99.90);
    ui->x_max->setMinimum(0);
    ui->y_min->setMinimum(-99.90);
    ui->y_max->setMinimum(0);

    setWindowTitle("Plot");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clearData()
{
    qv_x.clear();
    qv_y.clear();
    x_min = ui->x_min->value();
    x_max = ui->x_max->value();

    ui->plot->xAxis->setRange(ui->x_min->value(), ui->x_max->value());
    ui->plot->yAxis->setRange(ui->y_min->value(), ui->y_max->value());
}

void MainWindow::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y);
    ui->plot->replot();
    ui->plot->update();
}

void MainWindow::on_btn_clear_clicked()
{
    clearData();
    plot();
}

void MainWindow::on_cos_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( cos(ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );   //A * f(x + B) ^ C + D
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_sin_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
       qv_y.append( ui->bx_a->value() * pow( sin(ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_acos_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( acos(ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_asin_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
       qv_y.append( ui->bx_a->value() * pow( asin( ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_atan_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( atan( ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_ln_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( log( ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_x_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value(), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}


void MainWindow::on_e_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( exp(ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}


void MainWindow::on_circle_up_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append(sqrt (pow (ui->bx_a->value(), 2) - pow (qv_x.at(i) - ui->bx_b->value(), 2)) + ui->bx_c->value());
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_circle_down_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append(-sqrt (pow (ui->bx_a->value(), 2) - pow (qv_x.at(i) - ui->bx_b->value(), 2)) + ui->bx_c->value());
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_tg_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( (ui->bx_a->value() * pow( tan(ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value()) );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_ctg_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( 1/tan((ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value())), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_log_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_y.append(x_min);
        qv_x.append( ui->bx_a->value() * pow( (ui->bx_b->value() * pow(ui->bx_t->value(), qv_y.at(i)) + ui->bx_c->value()) , ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_a_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( pow( ui->bx_t->value(), ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value()), ui->bx_d->value()) + ui->bx_e->value() );
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_actg_clicked()
{
    clearData();
    for(int i=0; i<422; ++i)
    {
        qv_x.append(x_min);
        qv_y.append( ui->bx_a->value() * pow( atan(-( ui->bx_b->value() * qv_x.at(i) + ui->bx_c->value())), ui->bx_d->value()) + ui->bx_e->value() + M_PI/2);
        x_min = x_min + 0.05;
    }
    plot();
}

void MainWindow::on_actionInfo_triggered()
{
    AWindow->show();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString filter = "JPG files (*.jpg) ;; PNG files (*.png) ;; BMP files (*.bmp)";
    QString fileName = QFileDialog::getSaveFileName(this, tr("Зберегти як"), QDir::homePath(), filter);

                 QFile file(fileName);

                 if (!file.open(QIODevice::WriteOnly|QFile::WriteOnly))
                      {
                          QMessageBox::warning(0,"Did not create file",
                          QObject::tr( "\n Did not create file"));
                      }
                else {ui->plot->saveRastered( fileName,  0, 0, 1.0, 0 , -1);}
}

void MainWindow::on_actionInstruction_triggered()
{
    IWindow->show();
}
