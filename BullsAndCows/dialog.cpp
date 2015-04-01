#include "dialog.h"


Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
    setLayout(new QVBoxLayout);
    setMaximumSize(400,650);
    setMinimumSize(400,650);
    layout()->setMargin(5);
    layout()->setSpacing(3);
    imagePathBack = ":res/Image/back.png";
    menu = new Menu(this);
    numpad = new NumPad(this);
    numscore = new NumScore(this);
    game = new Game(8, 10, 5, this);
    QHBoxLayout* num = new QHBoxLayout;
    num->addWidget(numpad);
    num->addWidget(numscore);
    num->setSpacing(0);
    num->setMargin(0);
    layout()->addWidget(menu);
    layout()->addWidget(game);
    layout()->addItem(num);

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
    egw->show();
}

void Dialog::showScore()
{
    ScoreWindow* scw = new ScoreWindow();
    scw->show();
}

void Dialog::showInfo()
{
    InfoWindow* info = new InfoWindow();
    info->show();
}
