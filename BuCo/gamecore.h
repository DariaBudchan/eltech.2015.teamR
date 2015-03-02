#ifndef GAMECORE_H
#define GAMECORE_H

#include "number.h"

class GameCore
{
private:
    Number* secret_number;
    int max_try;
    int cur_try;
    int max_score;
    int cur_score;
    int bull_points;
    int cow_points;
    int num_size;
public:
    GameCore();
    GameCore(int tries, int b_p, int c_p);
    int getScore();
    int getStepsLast();
    void newGame();
    int makeGuess(int number);
    void changeBullPoint(int b_p);
    void changeCowPoint(int c_p);
    void changeTriesCount(int tries);
    ~GameCore();
};

#endif // GAMECORE_H
