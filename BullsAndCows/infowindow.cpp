#include "infowindow.h"

InfoWindow::InfoWindow(QWidget *parent) : QWidget(parent)
{
    QWidget::setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    setLayout(new QVBoxLayout);
    layout()->setAlignment(Qt::AlignBottom);
    QHBoxLayout* btn = new QHBoxLayout;
    btn->setAlignment(Qt::AlignHCenter);

    setMaximumSize(300,450);
    setMinimumSize(300,450);
    imagePathBack = ":res/Image/Info/back.png";

    btnOk = new CustomPushButton(50,80,this);
    btnOk->setImagePathDefault(":res/Image/Info/btnok.png");
    btnOk->setImagePathPressed(":res/Image/Info/btnokpressed.png");
    btnOk->setImagePathText(":res/Image/Info/btnoktext.png");

    btn->addWidget(btnOk);
    layout()->addItem(btn);

    connect(btnOk, SIGNAL(clicked()), this, SLOT(close()));
}

void InfoWindow::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(), QPixmap(imagePathBack));

    QFont f = p.font();
    f.setFamily("Arial");
    f.setPointSize(10);
    p.setFont(f);

    p.drawText(28, 30, 250, 350, 0, "This is game is about to gues the\n"
                                    "secret number.\n"
                                    "You must enter 4 uniq digits.\n"
                                    "For each correct digit you\n"
                                    "will see circle.\n"
                                    "If digit is on right place, circle will\n"
                                    "be green.\n"
                                    "If digit is not on right place, circle\n"
                                    "will be red.\n"
                                    "\n"
                                    "\n"
                                    "\n"
                                    "Game maked by:\n"
                                    "    Bolgarina Yulia\n"
                                    "    Budchan Daria\n"
                                    "    Zhangirov Timur");
}

InfoWindow::~InfoWindow()
{

}

