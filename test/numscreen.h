#ifndef NUMSCREEN_H
#define NUMSCREEN_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>

class NumScreen : public QWidget
{
    Q_OBJECT

    QLabel* labelNum1;
    QLabel* labelNum2;
    QLabel* labelNum3;
    QLabel* labelNum4;

    QPushButton* btnBackSpace;
    QPushButton* btnEnter;

    int cur_pos;

public:
    explicit NumScreen(QWidget *parent = 0);
    ~NumScreen();

signals:
    void sendNumber(int value);
public slots:
    void btnBackSpaceClicked();
    void btnEnterClicked();
    void numberEntered(int value);
};

#endif // NUMSCREEN_H
