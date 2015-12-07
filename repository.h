#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "scientist.h"
#include <QtSql>
#include <QString>
#include "constants.h"

using namespace std;


class Repository
{
public:
    Repository();
//    void print_to_file(string filename, vector<Scientist> s);
//    vector<Scientist> read_file(string filename);
    void connect_db(QString name);  
    vector<Scientist> open_scientist_db(QString sql_command);
private:
    QSqlDatabase db;
};

#endif // REPOSITORY_H
