#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include "stepresult.h"
#include "secretnumber.h"

class GameWidget : public QWidget
{
    Q_OBJECT
    SecretNumber* number;
    int max_try;
    int cur_try;
    int max_score;
    int cur_score;
    int bull_points;
    int cow_points;
    int num_size;
    bool isGameEnd;
public:
    explicit GameWidget(QWidget *parent = 0);
    GameWidget(int tries, int b_p, int c_p, QWidget *parent = 0);
    int getScore();
    int getStepsLast();
    ~GameWidget();
signals:
    void endGame(bool isWin, int score);
public slots:
    void makeGuess(int value);

};

#endif // GAMEWIDGET_H
