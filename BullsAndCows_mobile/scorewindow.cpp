#include "scorewindow.h"

#include <QVBoxLayout>
#include <QRect>
#include <QHBoxLayout>

ScoreWindow::ScoreWindow(QWidget *parent) : QWidget(parent)
{
    flag = true;
    QWidget::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);

    //setMaximumSize(300,550);
    //setMinimumSize(300,550);
    sworker = new ScoreWorker(this);
    //btnOk = new CustomPushButton(50,80,this);
    btnOk = new CustomPushButton(this);
    btnOk->setImagePathDefault(":res/Image/ScoreWindow/btnok.png");
    btnOk->setImagePathPressed(":res/Image/ScoreWindow/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/ScoreWindow/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

void ScoreWindow::paintEvent(QPaintEvent *pe)
{
    if(flag){
        btnOk->setMaximumSize(this->width()/4,this->height()/10);
        btnOk->setMinimumSize(this->width()/4,this->height()/10);
        flag = false;
    }
    QPainter p(this);
    p.drawPixmap(pe->rect(), QPixmap(":res/Image/ScoreWindow/back.png"));

    QFont f = p.font();
    f.setFamily("Arial");
    f.setPixelSize(this->height()/15*0.8);
    p.setFont(f);
    int last = this->height()/13;
    QString str = "  ";

    for(int i = 0; i < 10; i++){
        if(sworker->getScore(i) == 0)
            return;
        last += this->height()/15;
        if(i == 9)
            str = "";

        p.drawText(this->width()/3, last, this->width()/3, this->height()/15, 0,  QString::number(sworker->getScore(i)));
    }
}

ScoreWindow::~ScoreWindow()
{

}

