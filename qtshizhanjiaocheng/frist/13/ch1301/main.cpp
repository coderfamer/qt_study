#include <QCoreApplication>
#include <QTextCodec>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QTextCodec::setCodecForTr()
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("test");
    db.setDatabaseName("testDB.db");
    db.setUserName("quan");
    db.setPassword("123456");
    db.open();

    QSqlQuery query;
    bool success = query.exec("create table automobli"
                              "");



    return a.exec();
}
