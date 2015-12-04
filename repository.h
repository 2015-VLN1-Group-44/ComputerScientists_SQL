#ifndef REPOSITORY_H
#define REPOSITORY_H
#include <iostream>
#include <vector>
#include <iomanip>
#include "scientist.h"

using namespace std;


class Repository
{
public:
    Repository();
    void print_to_file(string filename, vector<Scientist> s);
    vector<Scientist> read_file(string filename);
private:
};

#endif // REPOSITORY_H
