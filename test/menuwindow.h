#ifndef MENUWINDOW_H
#define MENUWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MenuWindow : public QWidget
{
    Q_OBJECT
    QPushButton* btn1;
    QPushButton* btn2;
    QPushButton* btn3;
    QPushButton* btn4;
    QPushButton* btn5;
public:
    explicit MenuWindow(QWidget *parent = 0);
    ~MenuWindow();

signals:

public slots:
    void openMagic();
    void openRules();
    void openScore();
    void openPlay();
};

#endif // MENUWINDOW_H
