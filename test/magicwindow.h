#ifndef MAGICWINDOW_H
#define MAGICWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class MagicWindow : public QWidget
{
    Q_OBJECT
    QPushButton* backToMenu;
public:
    explicit MagicWindow(QWidget *parent = 0);
    ~MagicWindow();

signals:

public slots:
    void closeMagic();
};

#endif // MAGICWINDOW_H
