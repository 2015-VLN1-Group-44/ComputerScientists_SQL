#include "interface.h"

int main()
{
    Interface implement_test;
    bool quit;
    // Keyrir start menu - start_menu skilar false áður en búið er að gera quit
    do
    {
        quit = implement_test.start_menu();
    } while (!quit);

    return 0;
}
