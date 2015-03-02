#include <QHBoxLayout>
#include <QString>

#include "stepresult.h"

StepResult::StepResult(QWidget *parent) : QWidget(parent)
{
    setLayout(new QHBoxLayout);

    labelNum1 = new QLabel("_", this);
    labelNum2 = new QLabel("_", this);
    labelNum3 = new QLabel("_", this);
    labelNum4 = new QLabel("_", this);

    spliter = new QSplitter(Qt::Vertical, this);

    labelBC1 = new QLabel("BC", this);
    labelBC2 = new QLabel("BC", this);
    labelBC3 = new QLabel("BC", this);
    labelBC4 = new QLabel("BC", this);

    layout()->addWidget(labelNum1);
    layout()->addWidget(labelNum2);
    layout()->addWidget(labelNum3);
    layout()->addWidget(labelNum4);
    layout()->addWidget(spliter);
    layout()->addWidget(labelBC1);
    layout()->addWidget(labelBC2);
    layout()->addWidget(labelBC3);
    layout()->addWidget(labelBC4);
}

StepResult::StepResult(int value, int bull_and_cows, QWidget *parent)
{
    setLayout(new QHBoxLayout);

    int valuePart = value%10;
    value = value/10;
    labelNum4 = new QLabel(QString::number(valuePart), this);
    valuePart = value%10;
    value = value/10;
    labelNum3 = new QLabel(QString::number(valuePart), this);
    valuePart = value%10;
    value = value/10;
    labelNum2 = new QLabel(QString::number(valuePart), this);
    valuePart = value%10;
    labelNum1 = new QLabel(QString::number(valuePart), this);

    spliter = new QSplitter(Qt::Vertical, this);

    labelBC1 = new QLabel("_", this);
    labelBC2 = new QLabel("_", this);
    labelBC3 = new QLabel("_", this);
    labelBC4 = new QLabel("_", this);

    int bulls = bull_and_cows/10;
    int cows = bull_and_cows%10;
    int current = 0;

    for(int  i = 0; i < bulls; i++){
        switch (current) {
        case 0:
            labelBC1->setText("B");
            break;
        case 1:
            labelBC2->setText("B");
            break;
        case 2:
            labelBC3->setText("B");
            break;
        case 3:
            labelBC4->setText("B");
            break;
        default:
            break;
        }
        current++;
    }

    for(int  i = 0; i < cows; i++){
        switch (current) {
        case 0:
            labelBC1->setText("C");
            break;
        case 1:
            labelBC2->setText("C");
            break;
        case 2:
            labelBC3->setText("C");
            break;
        case 3:
            labelBC4->setText("C");
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
    layout()->addWidget(spliter);
    layout()->addWidget(labelBC1);
    layout()->addWidget(labelBC2);
    layout()->addWidget(labelBC3);
    layout()->addWidget(labelBC4);
}

StepResult::~StepResult()
{

}

