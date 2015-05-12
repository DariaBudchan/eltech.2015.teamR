#include "scoreworker.h"

ScoreWorker::ScoreWorker(QObject *parent) : QObject(parent)
{
    set = new QSettings("RTeam", "BullsAnsCows", this);

    for(int i = 0; i < 10; i++){
        score[i] = set->value("score"+QString::number(i), "0").toInt();
        if(score[i] == 9999)
            score[i] = 0;
    }
}

void ScoreWorker::addNew(int value)
{
    for(int i = 0; i < 10; i++){
        if(value > score[i]){
            for(int j = 9; j > i; j--){
                score[j] = score[j-1];
            }
            score[i] = value;
            return;
        }
    }

    save();
}

int ScoreWorker::getScore(int index)
{
    return score[index];
}

void ScoreWorker::save()
{
    for(int i = 0; i < 10; i++)
        set->setValue("score"+QString::number(i), score[i]);
}

ScoreWorker::~ScoreWorker()
{
    for(int i = 0; i < 10; i++)
        set->setValue("score"+QString::number(i), score[i]);
}

