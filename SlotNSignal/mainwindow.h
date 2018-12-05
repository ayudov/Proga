#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void signalFromButton(int buttonID);    // Сигнал для передачи номер нажатой кнопки

private:
    Ui::MainWindow *ui;

private slots:
    void slotButton1();     // Слоты-обработчики нажатий кнопок
    void slotButton2();
    void slotButton3();
    void slotButton4();

    // Слоты вызывающий сообщение с номеро нажатой кнопки
    void slotMessage(int buttonID);
};

#endif // MAINWINDOW_H
