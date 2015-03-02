#ifndef PLAYWINDOW_H
#define PLAYWINDOW_H

#include <QWidget>

#include "game.h"

class PlayWindow : public QWidget
{
    Q_OBJECT
    Game* game;
public:
    explicit PlayWindow(QWidget *parent = 0);
    ~PlayWindow();

signals:

public slots:
};

#endif // PLAYWINDOW_H
