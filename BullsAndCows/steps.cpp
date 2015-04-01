#include "steps.h"

Steps::Steps(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout* l = new QVBoxLayout;
    l->setAlignment(Qt::AlignTop);
    setLayout(l);
    setMaximumSize(390,475);
    setMinimumSize(390,475);
    layout()->setMargin(5);
    layout()->setSpacing(3);
    //imagePathBack = ":res/Image/StepResult/stepsback.png";
}

void Steps::addStep(int number, int bc)
{
    layout()->addWidget(new StepResult(number, bc, this));
}

Steps::~Steps()
{

}

void Steps::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(), imagePathBack);
}

