#include "loginwidget.h"
#include "ui_loginwidget.h"
#include "QSqlQuery"
#include "QMessageBox"
#include <QDebug>
#include <QSqlTableModel>

LoginWidget::LoginWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);  //将主窗体设置为这样的样式
}

LoginWidget::~LoginWidget()
{
    delete ui;
}


void LoginWidget::on_LoginButton_clicked()
{
    QString user;
    QString pwd;
    user=ui->NameLineEdit->text();
    pwd=ui->PwdLineEdit->text();
    if(user=="")
         QMessageBox::warning(this,"","用户名不能为空！");
    else if(pwd =="")
         QMessageBox::warning(this,"","密码不能为空！");
    else
    {
        //sql语句在数据库中进行查询验证
        QString S =QString("select * from login.User where user='%1' and pwd='%2' ").arg(user).arg(pwd);
        QSqlQuery query;
        query.exec(S);
        if(query.first())
        {
            QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
            ui->NameLineEdit->clear();
            ui->PwdLineEdit->clear();
            emit display(2);
        }
        else
        {
            QMessageBox::warning(NULL,"Error","登录失败，请重试！！！");
            ui->NameLineEdit->clear();
            ui->PwdLineEdit->clear();
        }

    }

}


void LoginWidget::on_QuitButton_clicked()
{
    QApplication::exit();
}

void LoginWidget::on_MinButton_clicked()
{
    this-> showMinimized();
}

void LoginWidget::on_ResigerButton_clicked()
{
    emit display(1);
}
