#include <iostream>
#include <algorithm>
#include <string>
#include "service.h"
#include <fstream> 
#include "interface.h"

using namespace std;

int main()
{
    Interface implement_test;
    bool quit;
    // Keyrir start menu - start_menu skilar false áður en búið er að gera quit
    // test
    do
    {
        quit = implement_test.start_menu();
    } while (!quit);

    return 0;
}
