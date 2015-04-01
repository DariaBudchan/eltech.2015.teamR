#include "numscore.h"


QString NumScore::getImagePathBack() const
{
    return imagePathBack;
}

void NumScore::setImagePathBack(const QString &value)
{
    imagePathBack = value;
}

void NumScore::paintEvent(QPaintEvent *pe)
{
    QPainter p(this);
    imagePathBack = ":/res/Image/NumScreen/back.png";
    p.drawPixmap(pe->rect(),imagePathBack);
}


void NumScore::btnBackSpaceClicked()
{
    if(cur_pos == 0)
        return;
    switch (cur_pos) {
    case 1:
        labelNum1->setImagePathText("");
        break;
    case 2:
        labelNum2->setImagePathText("");
        //cur_pos--;
        break;
    case 3:
        labelNum3->setImagePathText("");
        //cur_pos--;
        break;
    case 4:
        labelNum4->setImagePathText("");
        //cur_pos--;
        break;
    default:
        break;
    }
    update();
    cur_pos--;
    number[cur_pos] = 0;
}

void NumScore::btnEnterClicked()
{
    if(cur_pos != 4)
        return;

    int value = number[0]*1000+number[1]*100+number[2]*10+number[3];

    labelNum1->setImagePathText("");
    labelNum2->setImagePathText("");
    labelNum3->setImagePathText("");
    labelNum4->setImagePathText("");
    cur_pos = 0;
    update();
    emit sendNumber(value);
}

void NumScore::numberEntered(int value)
{
    QString str = ":res/Image/NumScreen/";

    if(cur_pos == 4)
        return;

    switch (cur_pos) {
    case 0:
        labelNum1->setImagePathText(str+QString::number(value)+".png");
        number[cur_pos] = value;
        cur_pos++;
        break;
    case 1:
        if(value != number[0])
        {
            labelNum2->setImagePathText(str+QString::number(value)+".png");
            number[cur_pos] = value;
            cur_pos++;
        }
        break;
    case 2:
        if(value != number[0] && value != number[1])
        {
            labelNum3->setImagePathText(str+QString::number(value)+".png");
            number[cur_pos] = value;
            cur_pos++;
        }
        break;
    case 3:
        if(value != number[0] && value != number[1] && value != number[2])
        {
            labelNum4->setImagePathText(str+QString::number(value)+".png");
            number[cur_pos] = value;
            cur_pos++;
        }
        break;
    default:
        break;
    }
    update();
}
NumScore::NumScore(QWidget *parent) : QWidget(parent)
{
    setLayout(new QVBoxLayout);

    setMaximumSize(230,100);
    setMinimumSize(230,100);

    imagePathBack = ":/res/Image/NumScreen/back.png";

    QHBoxLayout* buttons = new QHBoxLayout;
    buttons->setMargin(0);
    buttons->setSpacing(10);
    btnEnter = new CustomPushButton(35,35,this);
    btnEnter->setImagePathDefault(":res/Image/NumScreen/btn.png");
    btnEnter->setImagePathPressed(":res/Image/NumScreen/btnpressed.png");
    btnEnter->setImagePathText(":res/Image/NumScreen/enter.png");
    btnBackSpace = new CustomPushButton(35,35,this);
    btnBackSpace->setImagePathDefault(":res/Image/NumScreen/btn.png");
    btnBackSpace->setImagePathPressed(":res/Image/NumScreen/btnpressed.png");
    btnBackSpace->setImagePathText(":res/Image/NumScreen/backspace.png");
    buttons->setAlignment(Qt::AlignCenter);
    buttons->addWidget(btnBackSpace);
    buttons->addWidget(btnEnter);

    QHBoxLayout* nums = new QHBoxLayout;
    labelNum1 = new CustomLabel(60,50,this);
    labelNum1->setImagePathBackground(":res/Image/NumScreen/labelback.png");
    labelNum2 = new CustomLabel(60,50,this);
    labelNum2->setImagePathBackground(":res/Image/NumScreen/labelback.png");
    labelNum3 = new CustomLabel(60,50,this);
    labelNum3->setImagePathBackground(":res/Image/NumScreen/labelback.png");
    labelNum4 = new CustomLabel(60,50,this);
    labelNum4->setImagePathBackground(":res/Image/NumScreen/labelback.png");
    nums->setMargin(0);
    nums->setSpacing(0);
    nums->setAlignment(Qt::AlignHCenter);
    nums->addWidget(labelNum1);
    nums->addWidget(labelNum2);
    nums->addWidget(labelNum3);
    nums->addWidget(labelNum4);

    layout()->setMargin(0);
    layout()->setSpacing(0);

    layout()->addItem(nums);
    layout()->addItem(buttons);

    cur_pos = 0;
    number[0] = 0;
    number[1] = 0;
    number[2] = 0;
    number[3] = 0;

    connect(btnBackSpace, SIGNAL(clicked()), this, SLOT(btnBackSpaceClicked()));
    connect(btnEnter, SIGNAL(clicked()), this, SLOT(btnEnterClicked()));
}

NumScore::~NumScore()
{

}

