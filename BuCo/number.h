#ifndef NUMBER_H
#define NUMBER_H


class Number
{
private:
    int num[4];
public:
    Number();
    void Generate();
    int Compare(int comp_num);
    int getNum();
    ~Number();    
};

#endif // NUMBER_H
