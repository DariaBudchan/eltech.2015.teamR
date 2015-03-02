#include <QGridLayout>

#include "numpad.h"

NumPad::NumPad(QWidget *parent) : QWidget(parent)
{
    QGridLayout* grid = new QGridLayout;

    btn1 = new QPushButton("1",this);
    btn2 = new QPushButton("2",this);
    btn3 = new QPushButton("3",this);
    btn4 = new QPushButton("4",this);
    btn5 = new QPushButton("5",this);
    btn6 = new QPushButton("6",this);
    btn7 = new QPushButton("7",this);
    btn8 = new QPushButton("8",this);
    btn9 = new QPushButton("9",this);


    grid->addWidget(btn1,1,1);
    grid->addWidget(btn2,1,2);
    grid->addWidget(btn3,1,3);
    grid->addWidget(btn4,2,1);
    grid->addWidget(btn5,2,2);
    grid->addWidget(btn6,2,3);
    grid->addWidget(btn7,3,1);
    grid->addWidget(btn8,3,2);
    grid->addWidget(btn9,3,3);

    setLayout(grid);

    connect(btn1, SIGNAL(clicked()), this, SLOT(btn1Clicked()));
    connect(btn2, SIGNAL(clicked()), this, SLOT(btn2Clicked()));
    connect(btn3, SIGNAL(clicked()), this, SLOT(btn3Clicked()));
    connect(btn4, SIGNAL(clicked()), this, SLOT(btn4Clicked()));
    connect(btn5, SIGNAL(clicked()), this, SLOT(btn5Clicked()));
    connect(btn6, SIGNAL(clicked()), this, SLOT(btn6Clicked()));
    connect(btn7, SIGNAL(clicked()), this, SLOT(btn7Clicked()));
    connect(btn8, SIGNAL(clicked()), this, SLOT(btn8Clicked()));
    connect(btn9, SIGNAL(clicked()), this, SLOT(btn9Clicked()));

}

NumPad::~NumPad()
{

}

void NumPad::btn1Clicked()
{
    emit sendNumber(1);
}

void NumPad::btn2Clicked()
{
    emit sendNumber(2);
}

void NumPad::btn3Clicked()
{
    emit sendNumber(3);
}

void NumPad::btn4Clicked()
{
    emit sendNumber(4);
}

void NumPad::btn5Clicked()
{
    emit sendNumber(5);
}

void NumPad::btn6Clicked()
{
    emit sendNumber(6);
}

void NumPad::btn7Clicked()
{
    emit sendNumber(7);
}

void NumPad::btn8Clicked()
{
    emit sendNumber(8);
}

void NumPad::btn9Clicked()
{
    emit sendNumber(9);
}

