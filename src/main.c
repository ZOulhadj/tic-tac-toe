#include <stdio.h>
#include <stdbool.h>


// simple clear screen
#ifdef __unix__
#define CLEAR system("clear")
#elif _WIN32
#define CLEAR system("cls")
#endif

#define TABLE_SIZE 98

// defines for table positons within the array (TL = Top Left etc.)

// top row
#define TL 16
#define TM 20
#define TR 24

// middle row
#define ML 44
#define MM 48
#define MR 52

// bottom row
#define BL 72
#define BM 76
#define BR 80

char table[TABLE_SIZE];

void init_table();
void print_table();
void player_input();

int input;
bool isX = true;

int main()
{
    init_table();


    while (true) {
        CLEAR;

        print_table();

        player_input();
    }


    return 0;
}

void init_table()
{
    int i = 0;

    // first line
    while (i < 14) {
        if (i < 13) {
            table[i] = '_';
        } else {
            table[i] = '\n';
        }
        i++;
    }

    // rest of table

    // flag to switch between different lines for the table
    bool gaps = true;
    while (i < TABLE_SIZE) {
        if (gaps == true) {
            table[i] = '|';
            table[i + 1] = ' ';
            table[i + 2] = ' ';
            table[i + 3] = ' ';
            table[i + 4] = '|';
            table[i + 5] = ' ';
            table[i + 6] = ' ';
            table[i + 7] = ' ';
            table[i + 8] = '|';
            table[i + 9] = ' ';
            table[i + 10] = ' ';
            table[i + 11] = ' ';
            table[i + 12] = '|';
            table[i + 13] = '\n';
            i += 14;
            gaps = false;
        } else {
            table[i] = '|';
            table[i + 1] = '_';
            table[i + 2] = '_';
            table[i + 3] = '_';
            table[i + 4] = '|';
            table[i + 5] = '_';
            table[i + 6] = '_';
            table[i + 7] = '_';
            table[i + 8] = '|';
            table[i + 9] = '_';
            table[i + 10] = '_';
            table[i + 11] = '_';
            table[i + 12] = '|';
            table[i + 13] = '\n';

            i += 14;
            gaps = true;
        }
    }
}

void print_table()
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%c", table[i]);
    }
    printf("\n");

}

void player_input() {
    printf("Enter your box number (1-9): ");
    scanf("%d", &input);

    if (input == 1) {
        if (table[TL] == ' ') {
            table[TL] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 2) {
        if (table[TM] == ' ') {
            table[TM] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 3) {
        if (table[TR] == ' ') {
            table[TR] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 4) {
        if (table[ML] == ' ') {
            table[ML] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 5) {
        if (table[MM] == ' ') {
            table[MM] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 6) {
        if (table[MR] == ' ') {
            table[MR] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 7) {
        if (table[BL] == ' ') {
            table[BL] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 8) {
        if (table[BM] == ' ') {
            table[BM] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else if (input == 9) {
        if (table[BR] == ' ') {
            table[BR] = isX ? 'X' : 'O';
        } else {
            return;
        }
    } else {
        return;
    }

    // switch player
    if (isX) {
        isX = false;
    } else {
        isX = true;
    }
}
