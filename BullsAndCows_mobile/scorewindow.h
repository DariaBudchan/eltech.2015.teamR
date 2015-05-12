#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

#include "scoreworker.h"
#include "custompushbutton.h"

class ScoreWindow : public QWidget
{
    Q_OBJECT
    ScoreWorker* sworker;
    CustomPushButton* btnOk;
    bool flag;
public:
    explicit ScoreWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent* pe);
    ~ScoreWindow();

signals:

public slots:
};

#endif // SCOREWINDOW_H
