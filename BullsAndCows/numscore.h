#ifndef NUMSCORE_H
#define NUMSCORE_H

#include <QWidget>
#include <QString>
#include <QPaintEvent>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QKeyEvent>

#include "customlabel.h"
#include "custompushbutton.h"

class NumScore : public QWidget
{
    Q_OBJECT

    QString imagePathBack;

    CustomLabel* labelNum1;
    CustomLabel* labelNum2;
    CustomLabel* labelNum3;
    CustomLabel* labelNum4;

    CustomPushButton* btnBackSpace;
    CustomPushButton* btnEnter;

    int cur_pos;
    int number[4];

public:
    explicit NumScore(QWidget *parent = 0);
    ~NumScore();

    QString getImagePathBack() const;
    void setImagePathBack(const QString &value);

    void paintEvent(QPaintEvent* pe);

signals:
    void sendNumber(int value);
public slots:
    void btnBackSpaceClicked();
    void btnEnterClicked();
    void numberEntered(int value);
};

#endif // NUMSCORE_H
