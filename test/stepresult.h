#ifndef STEPRESULT_H
#define STEPRESULT_H

#include <QWidget>
#include <QLabel>
#include <QSplitter>

class StepResult : public QWidget
{
    Q_OBJECT
    QLabel* labelNum1;
    QLabel* labelNum2;
    QLabel* labelNum3;
    QLabel* labelNum4;

    QSplitter* spliter;

    QLabel* labelBC1;
    QLabel* labelBC2;
    QLabel* labelBC3;
    QLabel* labelBC4;

public:
    explicit StepResult(QWidget *parent = 0);
    StepResult(int value, int bull_and_cows, QWidget *parent = 0);
    ~StepResult();

signals:

public slots:
};

#endif // STEPRESULT_H
