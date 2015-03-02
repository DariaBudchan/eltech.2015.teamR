#include "number.h"
#include <cstdlib>
#include <ctime>

Number::Number()
{
    srand(time(NULL));
    num[0] = 1;
    num[1] = 2;
    num[2] = 3;
    num[3] = 4;
}

void Number::Generate()
{
    int val[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 9;
    int k = 0;
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    num[3] = 0;
    for(int i = 0; i < 4; i++){
        k = rand()%n;
        num[i] = val[k];
        for(int j = k; j < n-1; j++){
            val[j] = val[j+1];
        }
        n--;
    }
}

int Number::Compare(int comp_num)
{
    if(comp_num > 9999 || comp_num < 1000)
        return -1;

    int c_num[4] = {0,0,0,0};
    int t_val = 0;

    for(int i = 3; i >= 0; i--){
        t_val = comp_num%10;
        c_num[i] = t_val;
        comp_num = comp_num/10;
    }

    int bull_count = 0;
    for(int i = 0; i < 4; i++){
        if(c_num[i] == num[i])
            bull_count++;
    }

    int cow_count = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(c_num[i] == num[j] && i!=j)
            {
                cow_count++;
                break;
            }
        }
    }

    return 10*bull_count+cow_count;
}

int Number::getNum()
{
    int val = 0;
    for(int i = 0; i < 4; i++){
        val *= 10;
        val += num[i];
    }
    return val;
}

Number::~Number()
{

}



