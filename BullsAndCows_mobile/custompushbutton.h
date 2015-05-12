#ifndef CUSTOMPUSHBUTTON_H
#define CUSTOMPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QPaintEvent>
#include <QPainter>

class CustomPushButton : public QPushButton
{
    Q_OBJECT
    QString imagePathDefault;
    QString imagePathPressed;
    QString imagePathText;
public:
    explicit CustomPushButton(QWidget *parent = 0);
    CustomPushButton(int height, int width, QWidget *parent = 0);
    ~CustomPushButton();

    QString getImagePathPressed() const;
    void setImagePathPressed(const QString &value);

    QString getImagePathDefault() const;
    void setImagePathDefault(const QString &value);

    void paintEvent(QPaintEvent* pe);

    QString getImagePathText() const;
    void setImagePathText(const QString &value);

signals:

public slots:
};

#endif // CUSTOMPUSHBUTTON_H
