#include "numpad.h"


QString NumPad::getImagePathBackground() const
{
    return imagePathBackground;
}

void NumPad::setImagePathBackground(const QString &value)
{
    imagePathBackground = value;
}

void NumPad::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(), QPixmap(imagePathBackground));
}
NumPad::NumPad(QWidget *parent) : QWidget(parent)
{
    setMaximumSize(160,100);
    setMinimumSize(160,100);
    QGridLayout* grid = new QGridLayout;
    int btnHeight = 30;
    int btnWidth = 40;

    imagePathBackground = ":res/Image/NumPad/padbackground.png";

    btn_1 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_1->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_1->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_1->setImagePathText(":res/Image/NumPad/1.png");

    btn_2 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_2->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_2->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_2->setImagePathText(":res/Image/NumPad/2.png");

    btn_3 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_3->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_3->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_3->setImagePathText(":res/Image/NumPad/3.png");

    btn_4 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_4->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_4->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_4->setImagePathText(":res/Image/NumPad/4.png");

    btn_5 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_5->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_5->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_5->setImagePathText(":res/Image/NumPad/5.png");

    btn_6 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_6->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_6->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_6->setImagePathText(":res/Image/NumPad/6.png");

    btn_7 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_7->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_7->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_7->setImagePathText(":res/Image/NumPad/7.png");

    btn_8 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_8->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_8->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_8->setImagePathText(":res/Image/NumPad/8.png");

    btn_9 = new CustomPushButton(btnHeight, btnWidth, this);
    btn_9->setImagePathDefault(":res/Image/NumPad/btn.png");
    btn_9->setImagePathPressed(":res/Image/NumPad/btnpressed.png");
    btn_9->setImagePathText(":res/Image/NumPad/9.png");

    grid->addWidget(btn_1, 1, 1);
    grid->addWidget(btn_2, 1, 2);
    grid->addWidget(btn_3, 1, 3);
    grid->addWidget(btn_4, 2, 1);
    grid->addWidget(btn_5, 2, 2);
    grid->addWidget(btn_6, 2, 3);
    grid->addWidget(btn_7, 3, 1);
    grid->addWidget(btn_8, 3, 2);
    grid->addWidget(btn_9, 3, 3);

    setLayout(grid);
    layout()->setMargin(2);
    layout()->setSpacing(3);

    connect(btn_1, SIGNAL(clicked()), this, SLOT(btn1Clicked()));
    connect(btn_2, SIGNAL(clicked()), this, SLOT(btn2Clicked()));
    connect(btn_3, SIGNAL(clicked()), this, SLOT(btn3Clicked()));
    connect(btn_4, SIGNAL(clicked()), this, SLOT(btn4Clicked()));
    connect(btn_5, SIGNAL(clicked()), this, SLOT(btn5Clicked()));
    connect(btn_6, SIGNAL(clicked()), this, SLOT(btn6Clicked()));
    connect(btn_7, SIGNAL(clicked()), this, SLOT(btn7Clicked()));
    connect(btn_8, SIGNAL(clicked()), this, SLOT(btn8Clicked()));
    connect(btn_9, SIGNAL(clicked()), this, SLOT(btn9Clicked()));
}

NumPad::~NumPad()
{

}

int NumPad::btn1Clicked()
{
    emit numberEntered(1);
    return 1;
}

int NumPad::btn2Clicked()
{
    emit numberEntered(2);
    return 2;
}

int NumPad::btn3Clicked()
{
    emit numberEntered(3);
    return 3;
}

int NumPad::btn4Clicked()
{
    emit numberEntered(4);
    return 4;
}

int NumPad::btn5Clicked()
{
    emit numberEntered(5);
    return 5;
}

int NumPad::btn6Clicked()
{
    emit numberEntered(6);
    return 6;
}

int NumPad::btn7Clicked()
{
    emit numberEntered(7);
    return 7;
}

int NumPad::btn8Clicked()
{
    emit numberEntered(8);
    return 8;
}

int NumPad::btn9Clicked()
{
    emit numberEntered(9);
    return 9;
}

