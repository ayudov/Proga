#ifndef SAVE_H
#define SAVE_H

#include <QWidget>

namespace Ui {
class SaveWindow;
}

class SaveWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SaveWindow(QWidget *parent = 0);
    ~SaveWindow();

signals:
    void firstWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::SaveWindow *ui;
};



#endif // SAVE_H
