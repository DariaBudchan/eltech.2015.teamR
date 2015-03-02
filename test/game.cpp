#include <QVBoxLayout>
#include <QHBoxLayout>
#include <cstdlib>
#include <ctime>
#include <QString>

#include "game.h"

Game::Game(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout);
    srand(time(NULL));
    pad = new NumPad(this);
    screen = new NumScreen(this);
    gameW = new GameWidget(10,10,5,this);
    labelGameResult = new QLabel("&#9802", this);

    QHBoxLayout* enterNumber = new QHBoxLayout;
    enterNumber->addWidget(pad);
    enterNumber->addWidget(screen);

    layout()->addWidget(labelGameResult);
    layout()->addWidget(gameW);
    layout()->addItem(enterNumber);

    connect(pad, SIGNAL(sendNumber(int)), screen, SLOT(numberEntered(int)));
    connect(screen, SIGNAL(sendNumber(int)), gameW, SLOT(makeGuess(int)));
    connect(gameW, SIGNAL(endGame(bool,int)), this, SLOT(gameResult(bool,int)));

}

Game::~Game()
{

}

void Game::gameResult(bool isWin, int score)
{
    if(isWin){
        labelGameResult->setText("You Win. Your score: " + QString::number(score));
    }
    else{
        labelGameResult->setText("You Lose. Now you became a 'Bolgarskii ogurchik'");
    }
}

