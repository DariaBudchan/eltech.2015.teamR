#include "dialog.h"
#include <QApplication>
#include <ctime>
#include <cstdlib>

#include "numpad.h"
#include "menu.h"
#include "numscore.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));
    Dialog w;
   // w.height()/23;
    w.show();

    return a.exec();
}
