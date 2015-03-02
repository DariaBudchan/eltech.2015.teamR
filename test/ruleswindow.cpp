#include "ruleswindow.h"

RulesWindow::RulesWindow(QWidget *parent) :
    QWidget(parent)
{
    setFixedSize(300, 600);

    setLayout(new QVBoxLayout);
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint);

    backToMenu = new QPushButton("Back",this);
    layout()->addWidget(backToMenu);
    connect(backToMenu, SIGNAL(clicked()), this, SLOT(closeRules()));
}

RulesWindow::~RulesWindow()
{

}

void RulesWindow::closeRules()
{
    this->hide();
}
