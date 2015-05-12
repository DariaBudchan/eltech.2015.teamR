#ifndef NUMPAD_H
#define NUMPAD_H

#include <QWidget>
#include <QString>
#include <QPaintEvent>
#include <QPainter>
#include <QGridLayout>

#include "custompushbutton.h"

class NumPad : public QWidget
{
    Q_OBJECT
    CustomPushButton* btn_1;
    CustomPushButton* btn_2;
    CustomPushButton* btn_3;
    CustomPushButton* btn_4;
    CustomPushButton* btn_5;
    CustomPushButton* btn_6;
    CustomPushButton* btn_7;
    CustomPushButton* btn_8;
    CustomPushButton* btn_9;

    QString imagePathBackground;
    bool flag;
public:
    explicit NumPad(QWidget *parent = 0);
    ~NumPad();

    QString getImagePathBackground() const;
    void setImagePathBackground(const QString &value);

    void paintEvent(QPaintEvent* pe);

signals:
    void numberEntered(int value);
public slots:
    int btn1Clicked();
    int btn2Clicked();
    int btn3Clicked();
    int btn4Clicked();
    int btn5Clicked();
    int btn6Clicked();
    int btn7Clicked();
    int btn8Clicked();
    int btn9Clicked();
};

#endif // NUMPAD_H
