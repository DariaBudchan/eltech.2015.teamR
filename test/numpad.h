#ifndef NUMPAD_H
#define NUMPAD_H

#include <QWidget>
#include <QPushButton>

class NumPad : public QWidget
{
    Q_OBJECT
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;
    QPushButton* btn5;
    QPushButton* btn6;
    QPushButton* btn7;
    QPushButton* btn8;
    QPushButton* btn9;

public:
    explicit NumPad(QWidget *parent = 0);
    ~NumPad();

signals:
    void sendNumber(int value);
public slots:
    void btn1Clicked();
    void btn2Clicked();
    void btn3Clicked();
    void btn4Clicked();
    void btn5Clicked();
    void btn6Clicked();
    void btn7Clicked();
    void btn8Clicked();
    void btn9Clicked();
};

#endif // NUMPAD_H
