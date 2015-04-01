#include "scorewindow.h"

#include <QVBoxLayout>
#include <QRect>
#include <QHBoxLayout>

ScoreWindow::ScoreWindow(QWidget *parent) : QWidget(parent)
{
    QWidget::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);

    setMaximumSize(300,550);
    setMinimumSize(300,550);
    sworker = new ScoreWorker(this);
    btnOk = new CustomPushButton(50,80,this);
    btnOk->setImagePathDefault(":res/Image/ScoreWindow/btnok.png");
    btnOk->setImagePathPressed(":res/Image/ScoreWindow/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/ScoreWindow/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

void ScoreWindow::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(), QPixmap(":res/Image/ScoreWindow/back.png"));

    QFont f = p.font();
    f.setFamily("Arial");
    f.setPointSize(14);
    p.setFont(f);
    int last = 33;
    QString str = "  ";

    for(int i = 0; i < 10; i++){
        if(sworker->getScore(i) >= 9999)
            return;
        last += 37;
        if(i == 9)
            str = "";
        p.drawText(80, last, 40, 30, 0, str + QString::number(i+1) + ": ");
        p.drawText(120, last, 180, 30, 0,  QString::number(sworker->getScore(i)) + " sec");
    }
}

ScoreWindow::~ScoreWindow()
{

}

