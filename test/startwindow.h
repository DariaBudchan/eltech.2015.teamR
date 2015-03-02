#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>

class StartWindow : public QWidget
{
    Q_OBJECT
    QPushButton* btn;
public:
    StartWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent* pe);
    ~StartWindow();
public slots:
    void openMenu();
};

#endif // STARTWINDOW_H
