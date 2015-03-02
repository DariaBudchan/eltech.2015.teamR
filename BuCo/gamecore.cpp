#include "gamecore.h"

GameCore::GameCore()
{
    num_size = 4;
    max_try = 10;
    cur_try = 1;
    cow_points = 1;
    bull_points = 2;
    max_score = 0;
    for(int i = 1;i <= max_try; i++){
        max_score += i*num_size*bull_points;
    }
    cur_score = 0;
    secret_number = new Number();
}

GameCore::GameCore(int tries, int b_p, int c_p)
{
    num_size = 4;
    max_try = tries;
    cur_try = 1;
    cow_points = c_p;
    bull_points = b_p;
    max_score = 0;
    for(int i = 1;i <= max_try; i++){
        max_score += i*num_size*bull_points;
    }
    cur_score = 0;
    secret_number = new Number();
}

int GameCore::getScore()
{
    return max_score-cur_score;
}

int GameCore::getStepsLast()
{
    return max_try-cur_try;
}

void GameCore::newGame()
{
    cur_score = 0;
    cur_try = 1;
    secret_number->Generate();
}

int GameCore::makeGuess(int number)
{
    if(cur_try > max_try)
        return -2;
    int bc_count = secret_number->Compare(number);
    if(bc_count < 0)
        return -1;
    int b_count = bc_count/10;
    int c_count = bc_count%10;
    cur_score += cur_try*(num_size*bull_points-(b_count*bull_points+c_count*cow_points));
    cur_try++;
    return bc_count;
}

void GameCore::changeBullPoint(int b_p)
{
    bull_points = b_p;
}

void GameCore::changeCowPoint(int c_p)
{
    cow_points = c_p;
}

void GameCore::changeTriesCount(int tries)
{
    max_try = tries;
}

GameCore::~GameCore()
{

}

