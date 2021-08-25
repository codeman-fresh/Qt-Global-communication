#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"globalobserver.h"
#include"test.h"


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    test *t;
public slots:

    void slot_send();
};
#endif // WIDGET_H
