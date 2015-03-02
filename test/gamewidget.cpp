#include <QVBoxLayout>
#include "gamewidget.h"

GameWidget::GameWidget(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout);
    num_size = 4;
    max_try = 10;
    cur_try = 1;
    cow_points = 1;
    bull_points = 2;
    max_score = 0;
    isGameEnd = false;
    for(int i = 1;i <= max_try; i++){
        max_score += i*num_size*bull_points;
    }
    cur_score = 0;
    number = new SecretNumber(this);
    number->Generate();

}

GameWidget::GameWidget(int tries, int b_p, int c_p, QWidget *parent):
    QWidget(parent)
{
    setLayout(new QVBoxLayout);
    num_size = 4;
    max_try = tries;
    cur_try = 1;
    cow_points = c_p;
    bull_points = b_p;
    max_score = 0;
     isGameEnd = false;
    for(int i = 1;i <= max_try; i++){
        max_score += i*num_size*bull_points;
    }
    cur_score = 0;
    number = new SecretNumber(this);
    number->Generate();
}

int GameWidget::getScore()
{
    return max_score-cur_score;
}

int GameWidget::getStepsLast()
{
    return max_try-cur_try;
}

GameWidget::~GameWidget()
{

}

void GameWidget::makeGuess(int value)
{
    if(isGameEnd){
        return;
    }


    int bc_count = number->Compare(value);
    if(bc_count < 0)
        return;
    int b_count = bc_count/10;
    int c_count = bc_count%10;
    cur_score += cur_try*(num_size*bull_points-(b_count*bull_points+c_count*cow_points));
    cur_try++;

    layout()->addWidget(new StepResult(value, bc_count, this));

    if(bc_count == 40){
        isGameEnd = true;
        emit endGame(true, getScore());
        return;
    }

    if(cur_try > max_try)
    {
        isGameEnd = true;
        emit endGame(false, 0);
        return;
    }
}

