#include "registerwidegt.h"
#include "ui_registerwidegt.h"
#include "QSqlQuery"
#include "QMessageBox"
#include <QDebug>
#include <QSqlTableModel>

RegisterWidegt::RegisterWidegt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidegt)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);  //将主窗体设置为这样的样式
}

RegisterWidegt::~RegisterWidegt()
{
    delete ui;
}

void RegisterWidegt::on_ResigerButton_clicked()
{
    QString user;
    QString pwd;
    user=ui->NameLineEdit->text();
    pwd=ui->PwdLineEdit->text();
    if(user == "")
        QMessageBox::warning(this,"","用户名不能为空！");
    else if(pwd == "")
        QMessageBox::warning(this,"","密码不能为空！");
    else
    {
        QString i=QString("insert into login.User values ('%1','%2'); ").arg(user).arg(pwd);
        QString S =QString("select * from login.User where user='%1' ").arg(user);
        QSqlQuery query;
        if(query.exec(i))
        {
            QMessageBox::information(NULL, "注册成功", "注册成功！！！", QMessageBox::Yes);
            ui->NameLineEdit->clear();
            ui->PwdLineEdit->clear();
            emit display(0);
        }
        else if(query.exec(S)&&query.first())
        {
            QMessageBox::warning(NULL,"Error","用户名重复！！！");
            ui->NameLineEdit->clear();
            ui->PwdLineEdit->clear();
        }
        else
        {
            QMessageBox::warning(NULL,"Error","注册失败，请重试！！！");
            ui->NameLineEdit->clear();
            ui->PwdLineEdit->clear();
        }
    }
}


void RegisterWidegt::on_ReturnButton_clicked()
{
    emit display(0);
}
