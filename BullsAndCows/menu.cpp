#include "menu.h"


QString Menu::getImagePathBack() const
{
    return imagePathBack;
}

void Menu::setImagePathBack(const QString &value)
{
    imagePathBack = value;
}

void Menu::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(),imagePathBack);
}

void Menu::btnNewGameClicked()
{
    emit NewGame();
}

void Menu::btnScoreClicked()
{
    emit Score();
}

void Menu::btnInfoClicked()
{
    emit Info();
}

void Menu::btnExitClicked()
{
    emit Exit();
}
Menu::Menu(QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout);
    layout()->setMargin(0);
    layout()->setSpacing(0);
    setMaximumSize(400,50);
    setMinimumSize(400,50);

    imagePathBack = ":res/Image/Menu/menuback.png";

    btnNewGame = new CustomPushButton(50,100,this);
    btnNewGame->setImagePathDefault(":res/Image/Menu/btn.png");
    btnNewGame->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnNewGame->setImagePathText(":res/Image/Menu/newgame.png");

    btnScore = new CustomPushButton(50,100,this);
    btnScore->setImagePathDefault(":res/Image/Menu/btn.png");
    btnScore->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnScore->setImagePathText(":res/Image/Menu/score.png");

    btnInfo = new CustomPushButton(50,100,this);
    btnInfo->setImagePathDefault(":res/Image/Menu/btn.png");
    btnInfo->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnInfo->setImagePathText(":res/Image/Menu/info.png");

    btnExit = new CustomPushButton(50,100,this);
    btnExit->setImagePathDefault(":res/Image/Menu/btn.png");
    btnExit->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnExit->setImagePathText(":res/Image/Menu/exit.png");

    layout()->addWidget(btnNewGame);
    layout()->addWidget(btnScore);
    layout()->addWidget(btnInfo);
    layout()->addWidget(btnExit);

    connect(btnNewGame, SIGNAL(clicked()), this, SLOT(btnNewGameClicked()));
    connect(btnScore, SIGNAL(clicked()), this, SLOT(btnScoreClicked()));
    connect(btnInfo, SIGNAL(clicked()), this, SLOT(btnInfoClicked()));
    connect(btnExit, SIGNAL(clicked()), this, SLOT(btnExitClicked()));
}

Menu::~Menu()
{

}

