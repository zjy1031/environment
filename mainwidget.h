#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedLayout>
#include "registerwidegt.h"
#include "loginwidget.h"
#include "mainshowwidget.h"

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:


private:
    Ui::MainWidget *ui;
    LoginWidget *loginwidget;
    RegisterWidegt *registerwidget;
    MainshowWidget *mainshowwidget;
    QStackedLayout *stackLayout;   //QStackedLayout布局
};

#endif // MAINWIDGET_H
