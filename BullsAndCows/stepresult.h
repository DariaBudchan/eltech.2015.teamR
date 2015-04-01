#ifndef STEPRESULT_H
#define STEPRESULT_H

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QSplitter>

#include "customlabel.h"

class StepResult : public QWidget
{
    Q_OBJECT
    CustomLabel* labelNum1;
    CustomLabel* labelNum2;
    CustomLabel* labelNum3;
    CustomLabel* labelNum4;
    CustomLabel* labelBC1;
    CustomLabel* labelBC2;
    CustomLabel* labelBC3;
    CustomLabel* labelBC4;
    QSplitter* spliter;
    QString imagePathBack;

public:
    explicit StepResult(QWidget *parent = 0);
    StepResult(int value, int bull_and_cows, QWidget *parent = 0);

    void paintEvent(QPaintEvent* pe);
    ~StepResult();

signals:

public slots:
};

#endif // STEPRESULT_H
