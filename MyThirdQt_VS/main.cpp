#include "MyThirdQt_VS.h"
#include <QtWidgets/QApplication>
#include <QSqlDatabase>
#include <QtWidgets/qmessagebox.h>
#include <QProcess>
#include "createConnection.cpp"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    test1 w;
    w.show();
    return a.exec();
}
