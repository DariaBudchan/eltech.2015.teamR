#include "game.h"


Game::Game(int tries, int b_p, int c_p, QWidget *parent) : QWidget(parent)
{
    flag = true;
    setLayout(new QVBoxLayout);
    //layout()->setMargin(5);
    //setMaximumSize(390,485);
    //setMinimumSize(390,485);
    layout()->setMargin(0);
    layout()->setSpacing(0);
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
    history = new Steps(this);
    number->Generate();
    imagePathBack = ":res/Image/gameback.png";
    timer = new QTimer(this);
    startNewGame();
}

int Game::getScore()
{
    return 500*(cur_score+100)/cur_score;
}

int Game::getStepsLast()
{
    return max_try-cur_try;
}

void Game::paintEvent(QPaintEvent *pe)
{
    if(flag){
        history->setMaximumSize(this->width(),this->height());
        history->setMinimumSize(this->width(),this->height());
        flag = false;
    }
    QPainter p(this);
    p.drawPixmap(pe->rect(), imagePathBack);
}

void Game::timerEvent(QTimerEvent *te)
{
    if(!isGameEnd){
        cur_score++;
    }
}

Game::~Game()
{

}

void Game::makeGuess(int value)
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

    history->addStep(value, bc_count);
    update();

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

void Game::startNewGame()
{
    cur_score = 0;
    isGameEnd = false;
    number->Generate();
    cur_try = 1;
    history->~Steps();
    history = new Steps(this);
    if(flag){
        history->setMaximumSize(this->width(),this->height());
        history->setMinimumSize(this->width(),this->height());
        flag = false;
    }
    layout()->addWidget(history);
    timer->start(5000);
}

