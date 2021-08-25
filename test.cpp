#include "test.h"
#include<QDebug>
//class GlobalObserver;
test::test(QObject *parent) : QObject(parent)
{
    GlobalObserver::GetInstance()->attach("flag",this,SLOT(receiver()));

}
void test::receiver()
{
    qDebug()<<"test";
}

