#include "startwindow.h"
#include "menuwindow.h"
//#include <QPainter>
//#include <QPaintEvent>

StartWindow::StartWindow(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300, 600);

    setLayout(new QVBoxLayout);
    btn = new QPushButton("Open",this);
    layout()->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(openMenu()));
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);
/*
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(QImage("menu_background.png")));
    this->setPalette(palette);*/
}

void StartWindow::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(),QPixmap(":img/images/menu.png"));
}

StartWindow::~StartWindow()
{

}

void StartWindow::openMenu()
{
    this->hide();
    MenuWindow* menu = new MenuWindow();
    //menu->setStyleSheet("background-image: url(menu_background.png)");
    menu->show();
}
