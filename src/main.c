#include "table.h"

#include <stdlib.h> // system()

// simple clear screen
#ifdef __unix__
#define CLEAR system("clear")
#elif _WIN32
#define CLEAR system("cls")
#endif


int main()
{
    struct table table;

    init_table(&table);

    while (1) {
        CLEAR;

        print_table(&table);
        get_input(&table);
    }

    return 0;
}
