#ifndef ENDGAMEWINDOW_H
#define ENDGAMEWINDOW_H

#include <QWidget>
#include <QString>
#include <QPaintEvent>
#include <QPainter>
#include <QVBoxLayout>

#include "custompushbutton.h"

class EndGameWindow : public QWidget
{
    Q_OBJECT
    int scr;
    bool win;
    CustomPushButton* btnOk;
    bool flag;
public:
    explicit EndGameWindow(QWidget *parent = 0);
    EndGameWindow(bool isWin, int score, QWidget* parent = 0);
    void paintEvent(QPaintEvent* pe);
    ~EndGameWindow();

signals:

public slots:
};

#endif // ENDGAMEWINDOW_H
