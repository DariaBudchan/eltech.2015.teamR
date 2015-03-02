#include <QVBoxLayout>

#include "playwindow.h"

PlayWindow::PlayWindow(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout);
    game = new Game(this);

    layout()->addWidget(game);
}

PlayWindow::~PlayWindow()
{

}

