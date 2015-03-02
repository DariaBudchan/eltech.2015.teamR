#ifndef SCOREWINDOW_H
#define SCOREWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class ScoreWindow : public QWidget
{
    Q_OBJECT
    QPushButton* backToMenu;
public:
    explicit ScoreWindow(QWidget *parent = 0);
    ~ScoreWindow();
signals:

public slots:
    void closeScore();
};

#endif // SCOREWINDOW_H
