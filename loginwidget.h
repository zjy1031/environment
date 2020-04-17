#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>
#include <QSqlTableModel>


namespace Ui {
class LoginWidget;
}

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWidget(QWidget *parent = 0);
    ~LoginWidget();

private:
    Ui::LoginWidget *ui;

signals:
    void display(int number);
    
private slots:  
    void on_LoginButton_clicked();
    void on_ResigerButton_clicked();
    void on_QuitButton_clicked();
    void on_MinButton_clicked();
};

#endif // LOGINWIDGET_H
