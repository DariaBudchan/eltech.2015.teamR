#include "stepresult.h"

StepResult::StepResult(QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout);
    setMaximumSize(330,50);
    setMinimumSize(330,50);
    layout()->setMargin(0);

    //imagePathBack = ":res/Image/StepResult/back.png";

    labelNum1 = new CustomLabel(50,30,this);
    labelNum1->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum2 = new CustomLabel(50,30,this);
    labelNum2->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum3 = new CustomLabel(50,30,this);
    labelNum3->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum4 = new CustomLabel(50,30,this);
    labelNum4->setImagePathBackground(":res/Image/StepResult/numback.png");
    spliter = new QSplitter(Qt::Vertical, this);
    labelBC1 = new CustomLabel(50,50,this);
    labelBC1->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC2 = new CustomLabel(50,50,this);
    labelBC2->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC3 = new CustomLabel(50,50,this);
    labelBC3->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC4 = new CustomLabel(50,50,this);
    labelBC4->setImagePathBackground(":res/Image/StepResult/bcback.png");

    QHBoxLayout* lay_1 = new QHBoxLayout;
    lay_1->setAlignment(Qt::AlignLeft);
    labelNum1->setAlignment(Qt::AlignLeft);
    labelNum2->setAlignment(Qt::AlignLeft);
    labelNum3->setAlignment(Qt::AlignLeft);
    labelNum4->setAlignment(Qt::AlignLeft);
    lay_1->addWidget(labelNum1);
    lay_1->addWidget(labelNum2);
    lay_1->addWidget(labelNum3);
    lay_1->addWidget(labelNum4);


//    layout()->addWidget(labelNum1);
//    layout()->addWidget(labelNum2);
//    layout()->addWidget(labelNum3);
//    layout()->addWidget(labelNum4);
    layout()->addItem(lay_1);
    layout()->addWidget(spliter);
    layout()->addWidget(labelBC1);
    layout()->addWidget(labelBC2);
    layout()->addWidget(labelBC3);
    layout()->addWidget(labelBC4);
}

StepResult::StepResult(int value, int bull_and_cows, QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout);
    setMaximumSize(370,55);
    setMinimumSize(370,55);
    layout()->setMargin(1);
    layout()->setSpacing(3);

    imagePathBack = ":res/Image/StepResult/back.png";

    int valuePart = value%10;
    value = value/10;
    labelNum4 = new CustomLabel(53,35,this);
    labelNum4->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum4->setImagePathText(":res/Image/StepResult/"+QString::number(valuePart)+".png");

    valuePart = value%10;
    value = value/10;
    labelNum3 = new CustomLabel(53,35,this);
    labelNum3->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum3->setImagePathText(":res/Image/StepResult/"+QString::number(valuePart)+".png");

    valuePart = value%10;
    value = value/10;
    labelNum2 = new CustomLabel(53,35,this);
    labelNum2->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum2->setImagePathText(":res/Image/StepResult/"+QString::number(valuePart)+".png");

    valuePart = value%10;
    value = value/10;
    labelNum1 = new CustomLabel(53,35,this);
    labelNum1->setImagePathBackground(":res/Image/StepResult/numback.png");
    labelNum1->setImagePathText(":res/Image/StepResult/"+QString::number(valuePart)+".png");

    spliter = new QSplitter(Qt::Vertical, this);

    labelBC1 = new CustomLabel(53,53,this);
    labelBC1->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC2 = new CustomLabel(53,53,this);
    labelBC2->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC3 = new CustomLabel(53,53,this);
    labelBC3->setImagePathBackground(":res/Image/StepResult/bcback.png");
    labelBC4 = new CustomLabel(53,53,this);
    labelBC4->setImagePathBackground(":res/Image/StepResult/bcback.png");

    int bulls = bull_and_cows/10;
    int cows = bull_and_cows%10;
    int current = 0;

    for(int  i = 0; i < bulls; i++){
        switch (current) {
        case 0:
            labelBC1->setImagePathText(":res/Image/StepResult/bull.png");
            break;
        case 1:
            labelBC2->setImagePathText(":res/Image/StepResult/bull.png");
            break;
        case 2:
            labelBC3->setImagePathText(":res/Image/StepResult/bull.png");
            break;
        case 3:
            labelBC4->setImagePathText(":res/Image/StepResult/bull.png");
            break;
        default:
            break;
        }
        current++;
    }

    for(int  i = 0; i < cows; i++){
        switch (current) {
        case 0:
            labelBC1->setImagePathText(":res/Image/StepResult/cow.png");
            break;
        case 1:
            labelBC2->setImagePathText(":res/Image/StepResult/cow.png");
            break;
        case 2:
            labelBC3->setImagePathText(":res/Image/StepResult/cow.png");
            break;
        case 3:
            labelBC4->setImagePathText(":res/Image/StepResult/cow.png");
            break;
        default:
            break;
        }
        current++;
    }

    layout()->addWidget(labelNum1);
    layout()->addWidget(labelNum2);
    layout()->addWidget(labelNum3);
    layout()->addWidget(labelNum4);
    //layout()->addWidget(spliter);
    layout()->addWidget(labelBC1);
    layout()->addWidget(labelBC2);
    layout()->addWidget(labelBC3);
    layout()->addWidget(labelBC4);
}

void StepResult::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    p.drawPixmap(pe->rect(),imagePathBack);
}

StepResult::~StepResult()
{

}

