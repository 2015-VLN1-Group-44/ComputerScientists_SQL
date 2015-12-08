#ifndef COMPUTER_SERVICE_H
#define COMPUTER_SERVICE_H

#include "computers.h"
#include "repository.h"

class Computer_service
{
public:
    Computer_service();
    /* Takes column as argument, returns vector of computers
     *
     */
    vector<Computers> sort(QString sort_order);
    vector<Computers> search(QString column, QString search_arg);
    void edit_entry (QString column, QString argument, int id);
    Computers from_id(int id);
    void delete_id(int id);
    vector<string> connected_scientists(int id);
    void add_connection(int sci_id, int comp_id);
//    void read_input();

private:
    Repository computer_repo;
};

#endif // COMPUTER_SERVICE_H
