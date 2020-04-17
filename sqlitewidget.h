#ifndef SQLITEWIDGET_H
#define SQLITEWIDGET_H

#include <QWidget>

namespace Ui {
class SqliteWidget;
}

class SqliteWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SqliteWidget(QWidget *parent = 0);
    ~SqliteWidget();

private:
    Ui::SqliteWidget *ui;
};

#endif // SQLITEWIDGET_H
