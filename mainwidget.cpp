#include "mainwidget.h"
#include "ui_mainwidget.h"

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);  //实现了窗体上组件的创建、属性设置、信号与槽的关联
    loginwidget = new LoginWidget;
    registerwidget = new RegisterWidegt;
    mainshowwidget = new MainshowWidget;
    stackLayout = new QStackedLayout;

   //QStackedLayout *stackLayout; 多个界面放入stacklayout内
   //用addwidget方法
    stackLayout->addWidget(loginwidget);
    stackLayout->addWidget(registerwidget);
    stackLayout->addWidget(mainshowwidget);

   //流式布局 去掉会出现多个窗口
    setLayout(stackLayout);

   //QStackLayout中有 一个槽函数：setCurrentIndex(int Index) 可以设置当前显示的界面
    connect(loginwidget,&LoginWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(registerwidget,&RegisterWidegt::display, stackLayout, &QStackedLayout::setCurrentIndex);
    connect(mainshowwidget, &MainshowWidget::display, stackLayout, &QStackedLayout::setCurrentIndex);
}


MainWidget::~MainWidget()
{
    delete ui;
}


