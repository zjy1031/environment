#ifndef MAINSHOWWIDGET_H
#define MAINSHOWWIDGET_H

#include <QWidget>

namespace Ui {
class MainshowWidget;
}

class MainshowWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainshowWidget(QWidget *parent = 0);
    ~MainshowWidget();

protected:
    void paintEvent(QPaintEvent *event);
    QRectF textRectF(double radius, int pointSize, double angle);
signals:
    void display(int number);

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::MainshowWidget *ui;
};

#endif // MAINSHOWWIDGET_H
