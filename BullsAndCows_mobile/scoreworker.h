#ifndef SCOREWORKER_H
#define SCOREWORKER_H

#include <QObject>
#include <QSettings>

class ScoreWorker : public QObject
{
    Q_OBJECT
    int score[10];
    QSettings* set;
public:
    explicit ScoreWorker(QObject *parent = 0);
    void addNew(int value);
    int getScore(int index);
    void save();
    ~ScoreWorker();
signals:

public slots:
};

#endif // SCOREWORKER_H
