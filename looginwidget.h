#ifndef LOOGINWIDGET_H
#define LOOGINWIDGET_H

#include <QWidget>

namespace Ui {
class LooginWidget;
}

class LooginWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LooginWidget(QWidget *parent = 0);
    ~LooginWidget();

private:
    Ui::LooginWidget *ui;
};

#endif // LOOGINWIDGET_H
