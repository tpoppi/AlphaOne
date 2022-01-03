#include "scacchi.h"
#include "torre.h"
#include "cavallo.h"
#include "alfiere.h"
#include "scacchiera.h"
#include "vector.h"
#include <QApplication>
#include "controller.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Scacchiera m;
    Controller c(&m);
    Scacchi v(&c);
    c.setView(&v);
    v.show();
    return a.exec();
    return 0;
}
