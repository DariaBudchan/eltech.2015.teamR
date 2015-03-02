#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QString>


#include "numscreen.h"

NumScreen::NumScreen(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout);

    labelNum1 = new QLabel("_",this);
    labelNum2 = new QLabel("_",this);
    labelNum3 = new QLabel("_",this);
    labelNum4 = new QLabel("_",this);

    btnBackSpace = new QPushButton("BackSpace",this);
    btnEnter = new QPushButton("Enter",this);

    QHBoxLayout* number = new QHBoxLayout;
    number->addWidget(labelNum1);
    number->addWidget(labelNum2);
    number->addWidget(labelNum3);
    number->addWidget(labelNum4);

    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->addWidget(btnBackSpace);
    buttons->addWidget(btnEnter);

    layout()->addItem(number);
    layout()->addItem(buttons);

    cur_pos = 0;

    connect(btnBackSpace, SIGNAL(clicked()), this, SLOT(btnBackSpaceClicked()));
    connect(btnEnter, SIGNAL(clicked()), this, SLOT(btnEnterClicked()));
}

NumScreen::~NumScreen()
{

}

void NumScreen::btnBackSpaceClicked()
{
    if(cur_pos == 0)
        return;
    switch (cur_pos) {
    case 1:
        labelNum1->setText("_");
        cur_pos--;
        break;
    case 2:
        labelNum2->setText("_");
        cur_pos--;
        break;
    case 3:
        labelNum3->setText("_");
        cur_pos--;
        break;
    case 4:
        labelNum4->setText("_");
        cur_pos--;
        break;
    default:
        break;
    }
}

void NumScreen::btnEnterClicked()
{
    if(cur_pos != 4)
        return;

    int value = 0;
    value += labelNum1->text().toInt();
    labelNum1->setText("_");
    value *= 10;
    value += labelNum2->text().toInt();
    labelNum2->setText("_");
    value *= 10;
    value += labelNum3->text().toInt();
    labelNum3->setText("_");
    value *= 10;
    value += labelNum4->text().toInt();
    labelNum4->setText("_");
    cur_pos = 0;

    emit sendNumber(value);
}

void NumScreen::numberEntered(int value)
{
    QString str = QString::number(value);

    if(cur_pos == 4)
        return;

    switch (cur_pos) {
    case 0:
        labelNum1->setText(str);
        cur_pos++;
        break;
    case 1:
        if(value != labelNum1->text().toInt())
        {
            labelNum2->setText(str);
            cur_pos++;
        }
        break;
    case 2:
        if(value != labelNum1->text().toInt() && value != labelNum2->text().toInt())
        {
            labelNum3->setText(str);
            cur_pos++;
        }
        break;
    case 3:
        if(value != labelNum1->text().toInt() && value != labelNum2->text().toInt() && value != labelNum3->text().toInt())
        {
            labelNum4->setText(str);
            cur_pos++;
        }
        break;
    default:
        break;
    }

}

