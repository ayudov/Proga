#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <about.h>
#include <instruction.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void clearData();
    void plot();
    float x_min = -10;
    float x_max = 10;
    float y_max = 10;
    float y_min = -10;


private slots:
    void on_btn_clear_clicked();

    void on_cos_clicked();

    void on_sin_clicked();

    void on_acos_clicked();

    void on_asin_clicked();

    void on_atan_clicked();

    void on_ln_clicked();

    void on_x_clicked();

    void on_e_clicked();

    void on_circle_up_clicked();

    void on_circle_down_clicked();

    void on_tg_clicked();

    void on_ctg_clicked();

    void on_log_clicked();

    void on_a_clicked();

    void on_actionInfo_triggered();

    void on_actg_clicked();

    void on_actionSave_As_triggered();

    void on_actionInstruction_triggered();

private:
    Ui::MainWindow *ui;

    QVector<double> qv_x, qv_y;

    AboutWindow *AWindow;

    InstructionWindow *IWindow;
};

#endif // MAINWINDOW_H
