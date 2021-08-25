#include "widget.h"
#include <QMessageBox>
#include <QPushButton>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    t = new test();

    QPushButton *btn = new QPushButton("flag",this);//这个flag只是为了让起标识作用 让notify信号知道将那两个信号连接起来 也可以自己定义一个字符串
    connect(btn, SIGNAL(clicked()), this, SLOT(slot_send()));

}

Widget::~Widget()
{
    GlobalObserver::GetInstance()->detach("flag", this);

}


void Widget::slot_send()
{

    GlobalObserver::GetInstance()->notify("flag");
    qDebug()<<"flag";
}
