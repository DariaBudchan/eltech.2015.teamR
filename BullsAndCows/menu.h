#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QString>
#include <QHBoxLayout>
#include <QPaintEvent>
#include <QPainter>

#include "custompushbutton.h"

class Menu : public QWidget
{
    Q_OBJECT
    CustomPushButton* btnNewGame;
    CustomPushButton* btnScore;
    CustomPushButton* btnInfo;
    CustomPushButton* btnExit;

    QString imagePathBack;

public:
    explicit Menu(QWidget *parent = 0);
    ~Menu();

    QString getImagePathBack() const;
    void setImagePathBack(const QString &value);

    void paintEvent(QPaintEvent* pe);

signals:
    void NewGame();
    void Score();
    void Info();
    void Exit();
public slots:
    void btnNewGameClicked();
    void btnScoreClicked();
    void btnInfoClicked();
    void btnExitClicked();
};

#endif // MENU_H
