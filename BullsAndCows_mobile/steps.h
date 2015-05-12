#ifndef STEPS_H
#define STEPS_H

#include <QWidget>
#include <QString>
#include <QVBoxLayout>

#include "stepresult.h"

class Steps : public QWidget
{
    Q_OBJECT
    QString imagePathBack;
public:
    explicit Steps(QWidget *parent = 0);
    void addStep(int number, int bc);
    void paintEvent(QPaintEvent* pe);
    ~Steps();    
signals:

public slots:
};

#endif // STEPS_H
