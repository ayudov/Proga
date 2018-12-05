#ifndef ABOUT_H
#define ABOUT_H

#include <QWidget>

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

signals:
    void firstWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUT_H
