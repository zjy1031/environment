#ifndef REGISTERWIDEGT_H
#define REGISTERWIDEGT_H

#include <QWidget>

namespace Ui {
class RegisterWidegt;
}

class RegisterWidegt : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWidegt(QWidget *parent = 0);
    ~RegisterWidegt();

signals:
    void display(int number);

private slots:
    void on_ResigerButton_clicked();
    void on_ReturnButton_clicked();

private:
    Ui::RegisterWidegt *ui;
};

#endif // REGISTERWIDEGT_H
