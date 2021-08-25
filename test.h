#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "globalobserver.h"
//class GlobalObserver;
class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:
public slots:
    void receiver(); //处理函数


};

#endif // TEST_H
