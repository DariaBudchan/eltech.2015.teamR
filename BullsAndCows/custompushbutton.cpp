#include "custompushbutton.h"


QString CustomPushButton::getImagePathPressed() const
{
    return imagePathPressed;
}

void CustomPushButton::setImagePathPressed(const QString &value)
{
    imagePathPressed = value;
}

QString CustomPushButton::getImagePathDefault() const
{
    return imagePathDefault;
}

void CustomPushButton::setImagePathDefault(const QString &value)
{
    imagePathDefault = value;
}

void CustomPushButton::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    if(this->isDown()){
        p.drawPixmap(pe->rect(), QPixmap(imagePathPressed));
    }
    else{
        p.drawPixmap(pe->rect(), QPixmap(imagePathDefault));
    }
    p.drawPixmap(pe->rect(), QPixmap(imagePathText));
}

QString CustomPushButton::getImagePathText() const
{
    return imagePathText;
}

void CustomPushButton::setImagePathText(const QString &value)
{
    imagePathText = value;
}

CustomPushButton::CustomPushButton(QWidget *parent) :
    QPushButton(parent)
{
    imagePathDefault = "";
    imagePathPressed = "";
    imagePathText = "";
}

CustomPushButton::CustomPushButton(int height, int width, QWidget *parent):
    QPushButton(parent)
{
    setMaximumSize(width, height);
    setMinimumSize(width, height);
    imagePathDefault = "";
    imagePathPressed = "";
    imagePathText = "";
}

CustomPushButton::~CustomPushButton()
{

}

