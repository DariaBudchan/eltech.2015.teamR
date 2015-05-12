#include "customlabel.h"


QString CustomLabel::getImagePathText() const
{
    return imagePathText;
}

void CustomLabel::setImagePathText(const QString &value)
{
    imagePathText = value;
}

QString CustomLabel::getImagePathBackground() const
{
    return imagePathBackground;
}

void CustomLabel::setImagePathBackground(const QString &value)
{
    imagePathBackground = value;
}

void CustomLabel::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(),imagePathBackground);
    p.drawPixmap(pe->rect(),imagePathText);
}
CustomLabel::CustomLabel(QWidget *parent) :
    QLabel(parent)
{
    imagePathBackground = "";
    imagePathText = "";
}

CustomLabel::CustomLabel(int height, int width, QWidget *parent) :
    QLabel(parent)
{
    setMaximumSize(width, height);
    setMinimumSize(width, height);
    imagePathBackground = "";
    imagePathText = "";
}

CustomLabel::~CustomLabel()
{

}

