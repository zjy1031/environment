#include "looginwidget.h"
#include "ui_looginwidget.h"

LooginWidget::LooginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LooginWidget)
{
    ui->setupUi(this);
}

LooginWidget::~LooginWidget()
{
    delete ui;
}
