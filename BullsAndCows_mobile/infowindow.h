#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QString>
#include <QPainter>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "custompushbutton.h"

class InfoWindow : public QWidget
{
    Q_OBJECT
    CustomPushButton* btnOk;
    QString imagePathBack;
    bool flag;
public:
    explicit InfoWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent* pe);
    ~InfoWindow();

signals:

public slots:
};

#endif // INFOWINDOW_H
