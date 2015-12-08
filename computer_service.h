#ifndef COMPUTER_SERVICE_H
#define COMPUTER_SERVICE_H

#include "computers.h"
#include "repository.h"

class Computer_service
{
public:
    Computer_service();

//    void initialize(QString db_name);

    /* Takes column as argument, returns vector of computers
     *
     */
    vector<Computers> sort(QString sort_order);
    vector<Computers> search(QString column, QString search_arg);
    void edit_entry (QString column, QString argument, int id);
    Computers from_id(int id);
    vector<string> connected_scientists(int id);

private:
    Repository computer_repo;
};

#endif // COMPUTER_SERVICE_H
