#ifndef COMPUTER_SERVICE_H
#define COMPUTER_SERVICE_H

#include "computers.h"
#include "repository.h"

class Computer_service
{
public:
    Computer_service();

//    void initialize(QString db_name);
    vector<Computers> sort(QString sort_order);


private:
    Repository computer_repo;
};

#endif // COMPUTER_SERVICE_H
