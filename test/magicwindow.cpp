#include "magicwindow.h"

MagicWindow::MagicWindow(QWidget *parent) : QWidget(parent)
{
    setFixedSize(300, 600);

    setLayout(new QVBoxLayout);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    backToMenu = new QPushButton("Back",this);
    layout()->addWidget(backToMenu);
    connect(backToMenu, SIGNAL(clicked()), this, SLOT(closeMagic()));
}

MagicWindow::~MagicWindow()
{

}

void MagicWindow::closeMagic()
{
    this->hide();
}

