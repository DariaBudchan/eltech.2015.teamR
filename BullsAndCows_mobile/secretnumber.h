#ifndef SECRETNUMBER_H
#define SECRETNUMBER_H

#include <QObject>

class SecretNumber : public QObject
{
    Q_OBJECT
    int num[4];
public:
    explicit SecretNumber(QObject *parent = 0);
    void Generate();
    int Compare(int comp_num);
    int getNum();
    ~SecretNumber();
signals:

public slots:
};

#endif // SECRETNUMBER_H
