#include "endgamewindow.h"

#include <QHBoxLayout>

EndGameWindow::EndGameWindow(QWidget *parent) : QWidget(parent)
{
    flag = true;
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);
    //setMinimumSize(300,300);
    //setMaximumSize(300,300);

    win = false;
    scr = 0;

    //btnOk = new CustomPushButton(50,80,this);
    btnOk = new CustomPushButton(this);
    btnOk->setImagePathDefault(":res/Image/EndGameWindow/btnok.png");
    btnOk->setImagePathPressed(":res/Image/EndGameWindow/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/EndGameWindow/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

EndGameWindow::EndGameWindow(bool isWin, int score, QWidget *parent): QWidget(parent)
{
    QWidget::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);
    //setMinimumSize(300,300);
    //setMaximumSize(300,300);
    win = isWin;
    scr = score;

    btnOk = new CustomPushButton(50,80,this);
    btnOk->setImagePathDefault(":res/Image/EndGameWindow/btnok.png");
    btnOk->setImagePathPressed(":res/Image/EndGameWindow/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/EndGameWindow/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

void EndGameWindow::paintEvent(QPaintEvent *pe)
{
    if(flag){
        btnOk->setMaximumSize(this->width()/4,this->height()/10);
        btnOk->setMinimumSize(this->width()/4,this->height()/10);
        flag = false;
    }
    QPainter p(this);
    QFont f = p.font();
    f.setFamily("Impact");
    f.setPixelSize(this->height()/12);
    p.setFont(f);

    if(win)
    {
        p.drawPixmap(pe->rect(), QPixmap(":res/Image/EndGameWindow/win.png"));
       // p.drawText(100,100,100,100,0,QString::number(scr));
        p.drawText(this->width()/4,this->height()/5*2,this->width()/2,this->height()/5,Qt::AlignCenter,"Score:\n"+QString::number(scr));
    }else
    {
        p.drawPixmap(pe->rect(), QPixmap(":res/Image/EndGameWindow/lose.png"));
    }
}

EndGameWindow::~EndGameWindow()
{

}

