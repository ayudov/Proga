#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <QWidget>

namespace Ui {
class InstructionWindow;
}

class InstructionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit InstructionWindow(QWidget *parent = 0);
    ~InstructionWindow();

signals:
    void firstWindow();

private slots:

    void on_pushButton_clicked();

private:
    Ui::InstructionWindow *ui;
};

#endif // INSTRUCTION_H
