#ifndef GLOBALOBSERVER_H
#define GLOBALOBSERVER_H

#include <QObject>
#include "obesrverapater.h"
#pragma once

//class obesrverApater;

struct relationData
{
    QString type;
    QObject *receiver;
    obesrverApater *obesrverApater;
};

//class obesrverApater : public QObject
//{
//    Q_OBJECT
//public:
//    explicit obesrverApater(QObject *parent = nullptr);
//signals:
//    void notify(const QStringList&);
//};

class GlobalObserver : public QObject
{
    Q_OBJECT
public:
    static GlobalObserver* GetInstance();
    static GlobalObserver *m_pInstance;
    void attach(const QString  type, QObject * receiver, const char * method);
    void detach(const QString  type, const QObject* reciver);
    void notify(const QString  type);
private:
    GlobalObserver();
    ~GlobalObserver();
private:
    QList<relationData*> m_oRelationList;
};


#endif // GLOBALOBSERVER_H
