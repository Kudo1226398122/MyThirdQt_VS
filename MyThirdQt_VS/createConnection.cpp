#include <QSqlDatabase>
#include <QtWidgets/qmessagebox.h>
#include <QDebug>
#include <QSql>
#include <QSqlQuery>

using namespace std;
static QSqlDatabase db;

static bool createConnection() {
    qDebug() << "Available drivers:";
    QStringList drivers = QSqlDatabase::drivers();
    foreach(QString driver, drivers)
        qDebug() << driver;

    db = QSqlDatabase::addDatabase("QODBC");
    QString dsn = QString("DRIVER={MySQL ODBC 8.0 Unicode Driver};"
        "SERVER=%1;"
        "DATABASE=%2;"
        "UID=%3;"
        "PWD=%4;")
        .arg("localhost")
        .arg("test")
        .arg("root")
        .arg("18789513633gtxy");
    db.setDatabaseName(dsn);
    bool flag = db.open();
    if (flag) {
        return true;
    }
    else {
        return false;
    }
}