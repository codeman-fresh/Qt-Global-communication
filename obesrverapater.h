#ifndef OBESRVERAPATER_H
#define OBESRVERAPATER_H

#include <QObject>

class obesrverApater : public QObject
{
    Q_OBJECT
public:
    explicit obesrverApater(QObject *parent = nullptr);

signals:

    void notify();
};

#endif // OBESRVERAPATER_H
