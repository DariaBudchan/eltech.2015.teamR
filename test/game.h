#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QLabel>

#include "numpad.h"
#include "numscreen.h"
#include "gamewidget.h"

class Game : public QWidget
{
    Q_OBJECT
    NumPad* pad;
    NumScreen* screen;
    GameWidget* gameW;
    QLabel* labelGameResult;
public:
    explicit Game(QWidget *parent = 0);
    ~Game();

signals:

public slots:
    void gameResult(bool isWin, int score);

};

#endif // GAME_H
