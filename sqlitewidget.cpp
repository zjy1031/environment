#include "sqlitewidget.h"
#include "ui_sqlitewidget.h"

SqliteWidget::SqliteWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SqliteWidget)
{
    ui->setupUi(this);
}

SqliteWidget::~SqliteWidget()
{
    delete ui;
}
