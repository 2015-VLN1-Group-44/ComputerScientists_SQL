#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "scientist.h"
#include <QtSql>
#include <QString>
#include "constants.h"
#include "computers.h"

using namespace std;


class Repository
{
public:
    Repository();

//    void connect_db(QString name);
    vector<Scientist> open_scientist_db(QString sql_command);
    vector<Computers> open_computer_db(QString sql_command);
    void add_scientist(Scientist s);
    vector<string> connected(QString command);
private:
    QSqlDatabase db;
};

#endif // REPOSITORY_H
