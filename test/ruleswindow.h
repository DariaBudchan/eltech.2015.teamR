#ifndef RULESWINDOW_H
#define RULESWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class RulesWindow : public QWidget
{
    Q_OBJECT
    QPushButton* backToMenu;
public:
    explicit RulesWindow(QWidget *parent = 0);
    ~RulesWindow();
signals:

public slots:
    void closeRules();
};

#endif // RULESWINDOW_H
