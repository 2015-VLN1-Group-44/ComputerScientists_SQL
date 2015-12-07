#include "repository.h"


using namespace std;

Repository::Repository()
{
}

//void Repository::connect_db(QString name)
//{
//    db = QSqlDatabase::addDatabase("QSQLITE");
//    db.setDatabaseName(name);
//}

vector<Scientist> Repository::open_scientist_db(QString sql_command)
{
    vector<Scientist> data;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(constants::DATABASE_NAME);
    db.open();
    cerr << db.lastError().text().toStdString();
    QSqlQuery query(db);
    query.exec(sql_command);

    while (query.next())
    {
        string first, last;
        QDate b, d;
        bool g, a, act;
        int id_n;
        first = query.value("firstname").toString().toStdString();
        last = query.value("lastname").toString().toStdString();
        b = QDate::fromString(query.value("birth").toString(), constants::IMPORT_DATE_FORMAT);
        d = QDate::fromString(query.value("death").toString(), constants::IMPORT_DATE_FORMAT);
        id_n = query.value("id").toInt();
        g = query.value("gender").toBool();
        a = query.value("alive").toBool();
        act = query.value("active").toBool();
        Scientist temp(first, last, g, b, d, a, id_n, act);
        data.push_back(temp);
    }
    db.close();
    return data;
}

vector<Computers> Repository::open_computer_db(QString sql_command)
{
    vector<Computers> data;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(constants::DATABASE_NAME);
    db.open();
    db.open();
    cerr << db.lastError().text().toStdString();
    QSqlQuery query(db);
    query.exec(sql_command);

    while (query.next())
    {
        string name;
        int year, id_n;
        bool b, act;
        enum computer_type ct;

        name = query.value("name").toString().toStdString();
        ct = static_cast<computer_type>(query.value("type").toInt());
        year = query.value("built_year").toInt();
        id_n = query.value("id").toInt();
        b = query.value("built").toBool();
        act = query.value("active").toBool();
        Computers temp(name, year, b, ct, id_n, act);
        data.push_back(temp);
    }
    db.close();
    return data;    
}

void Repository::add_scientist(Scientist s)
{
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(constants::DATABASE_NAME);
    db.open();
    QSqlQuery query(db);
    query.prepare(constants::INSERT_FORM);
    query.bindValue(":first", QString::fromStdString(s.get_first()));
    query.bindValue(":last", QString::fromStdString(s.get_last()));
    query.bindValue(":b", s.get_birth());
    query.bindValue(":d", s.get_death());
    query.bindValue(":g", s.get_gender());
    query.bindValue(":a", s.get_living());
    query.bindValue(":act", 1);
    query.exec();

}
