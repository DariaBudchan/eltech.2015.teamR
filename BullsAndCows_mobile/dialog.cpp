#include "dialog.h"


Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
    flag = true;
    setLayout(new QVBoxLayout);
    //setMaximumSize(480,640);
    setMinimumSize(300,500);
    layout()->setMargin(0);
    layout()->setSpacing(0);
    layout()->setAlignment(Qt::AlignTop | Qt::AlignHCenter);// !!
    imagePathBack = ":res/Image/back.png";
    menu = new Menu(this);
    //menu->setMinimumSize(this->width(),this->height()/13);
    //menu->setMaximumSize(this->width(),this->height()/13);
    //this->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
    numpad = new NumPad(this);
    numscore = new NumScore(this);
    game = new Game(8, 10, 5, this);
    QHBoxLayout* num = new QHBoxLayout;
    //num->setAlignment(Qt::AlignBottom); // !!
    num->addWidget(numpad);
    num->addWidget(numscore);
    num->setSpacing(0);
    num->setMargin(0);
    num->setAlignment(Qt::AlignHCenter);
    layout()->addWidget(menu);
    layout()->addWidget(game);
    layout()->addItem(num);
    game->startNewGame();

    connect(numpad,SIGNAL(numberEntered(int)), numscore, SLOT(numberEntered(int)));
    connect(menu, SIGNAL(Exit()), this, SLOT(close()));
    connect(numscore, SIGNAL(sendNumber(int)), game, SLOT(makeGuess(int)));
    connect(menu, SIGNAL(NewGame()), game, SLOT(startNewGame()));
    connect(game, SIGNAL(endGame(bool,int)), this, SLOT(endGame(bool,int)));
    connect(menu, SIGNAL(Score()), this, SLOT(showScore()));
    connect(menu, SIGNAL(Info()), this, SLOT(showInfo()));

}

void Dialog::paintEvent(QPaintEvent *pe)
{
    if(flag){
        menu->setMinimumSize(this->width(),this->height()/13);
        menu->setMaximumSize(this->width(),this->height()/13);
        game->setMinimumSize(this->width(),this->height()/13*9);
        game->setMaximumSize(this->width(),this->height()/13*9);
        numpad->setMinimumSize(this->height()/13*3,this->height()/13*3);
        numpad->setMaximumSize(this->height()/13*3,this->height()/13*3);
        numscore->setMinimumSize(this->width()-this->height()/13*3,this->height()/13*3);
        numscore->setMaximumSize(this->width()-this->height()/13*3,this->height()/13*3);
        flag = false;
    }
    QPainter p(this);
    p.drawPixmap(pe->rect(), imagePathBack);
}

void Dialog::keyPressEvent(QKeyEvent *ke)
{
    switch (ke->nativeScanCode()) {

    case 2:
        numscore->numberEntered(1);
        break;
    case 3:
        numscore->numberEntered(2);
        break;
    case 4:
        numscore->numberEntered(3);
        break;
    case 5:
        numscore->numberEntered(4);
        break;
    case 6:
        numscore->numberEntered(5);
        break;
    case 7:
        numscore->numberEntered(6);
        break;
    case 8:
        numscore->numberEntered(7);
        break;
    case 9:
        numscore->numberEntered(8);
        break;
    case 10:
        numscore->numberEntered(9);
        break;
    case 28:
        numscore->btnEnterClicked();
        break;
    case 14:
        numscore->btnBackSpaceClicked();
        break;
    case 79:
        numscore->numberEntered(1);
        break;
    case 80:
        numscore->numberEntered(2);
        break;
    case 81:
        numscore->numberEntered(3);
        break;
    case 75:
        numscore->numberEntered(4);
        break;
    case 76:
        numscore->numberEntered(5);
        break;
    case 77:
        numscore->numberEntered(6);
        break;
    case 71:
        numscore->numberEntered(7);
        break;
    case 72:
        numscore->numberEntered(8);
        break;
    case 73:
        numscore->numberEntered(9);
        break;
    default:
        break;
    }
}

Dialog::~Dialog()
{

}

void Dialog::endGame(bool isWin, int score)
{
    ScoreWorker sworker(this);
    if(isWin){
        sworker.addNew(score);
    }

    EndGameWindow* egw = new EndGameWindow(isWin, score);
    egw->setMaximumSize(this->width(),this->height());
    egw->setMinimumSize(this->width(),this->height());
    egw->show();
}

void Dialog::showScore()
{
    ScoreWindow* scw = new ScoreWindow();
    scw->setMaximumSize(this->width(),this->height());
    scw->setMinimumSize(this->width(),this->height());
    scw->show();
}

void Dialog::showInfo()
{
    InfoWindow* info = new InfoWindow();
    info->setMaximumSize(this->width(),this->height());
    info->setMinimumSize(this->width(),this->height());
    info->show();
}
