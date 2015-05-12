#include "infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) : QWidget(parent)
{
    flag = true;
    QWidget::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);

    //setMaximumSize(300,450);
    //setMinimumSize(300,450);
    imagePathBack = ":res/Image/Info/back.png";

    //btnOk = new CustomPushButton(50,80,this);
    btnOk = new CustomPushButton(this);
    btnOk->setImagePathDefault(":res/Image/Info/btnok.png");
    btnOk->setImagePathPressed(":res/Image/Info/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/Info/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

void InfoWindow::paintEvent(QPaintEvent *pe)
{
    if(flag){
        btnOk->setMaximumSize(this->width()/4,this->height()/10);
        btnOk->setMinimumSize(this->width()/4,this->height()/10);
        flag = false;
    }
    QPainter p(this);
    p.drawPixmap(pe->rect(), QPixmap(imagePathBack));

    QFont f = p.font();
    f.setFamily("Arial");
    //f.setPointSize((this->height()/140)*0.7);
    f.setPixelSize(this->height()*8/240);
    p.setFont(f);

    p.drawText(this->width()/11, this->height()/10, this->width()*9/11, this->height()*8/10, 0,
                                    "This is game is about to gues\n"
                                    "the secret number.\n"
                                    "You must enter 4 uniq digits.\n"
                                    "For each correct digit you\n"
                                    "will see circle.\n"
                                    "If digit is on right place,\n"
                                    "circle will be green.\n"
                                    "If digit is not on right place,\n"
                                    "circle will be red.\n"
                                    "\n"
                                    "\n"
                                    "Created by TeamR");
}

InfoWindow::~InfoWindow()
{

}

