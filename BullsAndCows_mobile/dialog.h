#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include <QPaintEvent>
#include <QPainter>

#include "menu.h"
#include "numpad.h"
#include "numscore.h"
#include "game.h"
#include "scoreworker.h"
#include "endgamewindow.h"
#include "scorewindow.h"
#include "infowindow.h"

class Dialog : public QWidget
{
    Q_OBJECT
    Menu* menu;
    NumPad* numpad;
    NumScore* numscore;
    Game* game;
    QString imagePathBack;
    bool flag;
public:
    Dialog(QWidget *parent = 0);
    void paintEvent(QPaintEvent* pe);
    void keyPressEvent(QKeyEvent* ke);
    ~Dialog();
public slots:
    void endGame(bool isWin, int score);
    void showScore();
    void showInfo();
};

#endif // DIALOG_H
