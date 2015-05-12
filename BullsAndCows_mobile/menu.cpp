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
    if(flag){
        btnNewGame->setMaximumSize(this->width()/4,this->height());
        btnNewGame->setMinimumSize(this->width()/4,this->height());
        btnScore->setMaximumSize(this->width()/4,this->height());
        btnScore->setMinimumSize(this->width()/4,this->height());
        btnInfo->setMaximumSize(this->width()/4,this->height());
        btnInfo->setMinimumSize(this->width()/4,this->height());
        btnExit->setMaximumSize(this->width()/4,this->height());
        btnExit->setMinimumSize(this->width()/4,this->height());
        flag = false;
    }
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
    flag = true;
    setLayout(new QHBoxLayout);
    layout()->setMargin(0);
    layout()->setSpacing(0);
    //setMaximumSize(400,50);
    //setMinimumSize(400,50);
    layout()->setAlignment(Qt::AlignHCenter);

    imagePathBack = ":res/Image/Menu/menuback.png";

    //btnNewGame = new CustomPushButton(this->height(),this->width()/4,this);
    btnNewGame = new CustomPushButton(this);
    //btnNewGame->setMaximumSize(this->width()/4,this->height());
    //btnNewGame->setMinimumSize(this->width()/4,this->height());
    btnNewGame->setImagePathDefault(":res/Image/Menu/btn.png");
    btnNewGame->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnNewGame->setImagePathText(":res/Image/Menu/newgame.png");

    //btnScore = new CustomPushButton(this->height(),this->width()/4,this);
    btnScore = new CustomPushButton(this);
    //btnScore->setMaximumSize(this->width()/4,this->height());
    //btnScore->setMinimumSize(this->width()/4,this->height());
    btnScore->setImagePathDefault(":res/Image/Menu/btn.png");
    btnScore->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnScore->setImagePathText(":res/Image/Menu/score.png");

    //btnInfo = new CustomPushButton(this->height(),this->width()/4,this);
    btnInfo = new CustomPushButton(this);
    //btnInfo->setMaximumSize(this->width()/4,this->height());
    //btnInfo->setMinimumSize(this->width()/4,this->height());
    btnInfo->setImagePathDefault(":res/Image/Menu/btn.png");
    btnInfo->setImagePathPressed(":res/Image/Menu/btnpressed.png");
    btnInfo->setImagePathText(":res/Image/Menu/info.png");

    //btnExit = new CustomPushButton(this->height(),this->width()/4,this);
    btnExit = new CustomPushButton(this);
    //btnExit->setMaximumSize(this->width()/4,this->height());
    //btnExit->setMinimumSize(this->width()/4,this->height());
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

