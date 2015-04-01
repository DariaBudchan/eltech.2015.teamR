#include "endgamewindow.h"

#include <QHBoxLayout>

EndGameWindow::EndGameWindow(QWidget *parent) : QWidget(parent)
{

    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);
    setMinimumSize(300,300);
    setMaximumSize(300,300);

    win = false;
    scr = 0;

    btnOk = new CustomPushButton(50,80,this);
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
    setMinimumSize(300,300);
    setMaximumSize(300,300);
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
    QPainter p(this);
    QFont f = p.font();
    f.setFamily("Impact");
    f.setPointSize(30);
    p.setFont(f);

    if(win)
    {
        p.drawPixmap(pe->rect(), QPixmap(":res/Image/EndGameWindow/win.png"));
        p.drawText(100,100,100,100,0,QString::number(scr));
    }else
    {
        p.drawPixmap(pe->rect(), QPixmap(":res/Image/EndGameWindow/lose.png"));
    }
}

EndGameWindow::~EndGameWindow()
{

}

