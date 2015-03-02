#include "menuwindow.h"
#include "main.cpp"
#include "magicwindow.h"
#include "ruleswindow.h"
#include "scorewindow.h"
#include "playwindow.h"

MenuWindow::MenuWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 600);



    setLayout(new QVBoxLayout);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    btn1 = new QPushButton("Play",this);
    layout()->addWidget(btn1);
    connect(btn1, SIGNAL(clicked()), this, SLOT(openPlay()));

    btn2 = new QPushButton("Score",this);
    layout()->addWidget(btn2);
    connect(btn2, SIGNAL(clicked()), this, SLOT(openScore()));

    btn3 = new QPushButton("Rules",this);
    layout()->addWidget(btn3);
    connect(btn3, SIGNAL(clicked()), this, SLOT(openRules()));

    btn4 = new QPushButton("Magic",this);
    layout()->addWidget(btn4);
    connect(btn4, SIGNAL(clicked()), this, SLOT(openMagic()));

    btn5 = new QPushButton("Exit",this);
    layout()->addWidget(btn5);
    connect(btn5, SIGNAL(clicked()), this, SLOT(close()));

}

MenuWindow::~MenuWindow()
{

}

void MenuWindow::openMagic()
{
    MagicWindow* magic = new MagicWindow();
    magic->show();
}

void MenuWindow::openRules()
{
    RulesWindow* rules = new RulesWindow();
    rules->show();
}

void MenuWindow::openScore()
{
    ScoreWindow* score = new ScoreWindow();
    score->show();
}

void MenuWindow::openPlay()
{
    PlayWindow* play = new PlayWindow();
    play->show();
}
