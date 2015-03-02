#include <QCoreApplication>
#include "number.h"
#include "gamecore.h"
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    GameCore* gcore = new GameCore(10, 10, 5);
    int num;
    int p;
    bool flag = false;
    while(true){
        gcore->newGame();
        flag = false;
        cout << "\nNew game!!1111\n";
        while(gcore->getStepsLast() >= 0){
            cout << "   Enter number: ";
            cin >> num;
            p = gcore->makeGuess(num);
            if(p < 0)
                continue;
            cout << "   bc: " << p << endl;
            if(p == 40){
                flag = true;
                break;
            }
        }
        if(flag)
            cout << "You win: " << gcore->getScore() ;
        else
            cout << "LOSER!!!";
    }

    return a.exec();
}
