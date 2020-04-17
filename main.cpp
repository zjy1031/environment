#include "mainwidget.h"
#include "loginwidget.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>

void connectmysql()  //连接数据库
{
    //添加mysql数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");//添加数据库驱动
    db.setHostName("localhost");      //连接数据库主机名，这里需要注意（若填的为”127.0.0.1“，出现不能连接，则改为localhost)
    db.setPort(3306);                 //连接数据库端口号，与设置一致
    db.setDatabaseName("login");  //连接数据库名，与设置一致
    db.setUserName("root");          //数据库用户名，与设置一致
    //db.setPassword("123456");    //数据库密码，与设置一致
    db.open();
    //打开数据库
    if(!db.open())
    {
        qDebug()<<"不能连接"<<"connect to mysql error"<<db.lastError().text();
        return;
    }
    else
    {
        qDebug()<<"连接成功"<<"connect to mysql OK";
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWidget w;
    connectmysql();  //调用数据库函数
    w.show();
    return a.exec();
}
