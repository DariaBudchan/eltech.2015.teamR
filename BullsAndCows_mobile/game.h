#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QTimerEvent>
#include <QTimer>

#include "secretnumber.h"
#include "steps.h"

class Game : public QWidget
{
    Q_OBJECT
    SecretNumber* number;
    Steps* history;
    int max_try;
    int cur_try;
    int max_score;
    int cur_score;
    int bull_points;
    int cow_points;
    int num_size;
    bool isGameEnd;
    QString imagePathBack;
    QTimer* timer;
    bool flag;
public:
    Game(int tries, int b_p, int c_p, QWidget *parent = 0);
    int getScore();
    int getStepsLast();
    void paintEvent(QPaintEvent* pe);
    void timerEvent(QTimerEvent* te);
    ~Game();
signals:
    void endGame(bool isWin, int score);
public slots:
    void makeGuess(int value);
    void startNewGame();
};

#endif // GAME_H
