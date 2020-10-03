#include "table.h"

#include <stdio.h>
#include <stdbool.h>

bool isX = true;

void init_table(struct table *table)
{
    int i = 0;

    // first line
    while (i < 14) {
        if (i < 13) {
            table->buffer[i] = '_';
        } else {
            table->buffer[i] = '\n';
        }
        i++;
    }

    // rest of table

    // flag to switch between different lines for the table
    bool gaps = true;
    while (i < TABLE_SIZE) {
        if (gaps == true) {
            table->buffer[i] = '|';
            table->buffer[i + 1] = ' ';
            table->buffer[i + 2] = ' ';
            table->buffer[i + 3] = ' ';
            table->buffer[i + 4] = '|';
            table->buffer[i + 5] = ' ';
            table->buffer[i + 6] = ' ';
            table->buffer[i + 7] = ' ';
            table->buffer[i + 8] = '|';
            table->buffer[i + 9] = ' ';
            table->buffer[i + 10] = ' ';
            table->buffer[i + 11] = ' ';
            table->buffer[i + 12] = '|';
            table->buffer[i + 13] = '\n';
            i += 14;
            gaps = false;
        } else {
            table->buffer[i] = '|';
            table->buffer[i + 1] = '_';
            table->buffer[i + 2] = '_';
            table->buffer[i + 3] = '_';
            table->buffer[i + 4] = '|';
            table->buffer[i + 5] = '_';
            table->buffer[i + 6] = '_';
            table->buffer[i + 7] = '_';
            table->buffer[i + 8] = '|';
            table->buffer[i + 9] = '_';
            table->buffer[i + 10] = '_';
            table->buffer[i + 11] = '_';
            table->buffer[i + 12] = '|';
            table->buffer[i + 13] = '\n';

            i += 14;
            gaps = true;
        }
    }
}

void print_table(struct table *table)
{
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("%c", table->buffer[i]);
    }
    printf("\n");

}

void get_input(struct table *table)
{

    printf("Enter your box number (1-9): ");

    int input;
    scanf("%d", &input);

    // set corresponding input box
    int tp = 0;

    switch (input) {
    case 1:
        tp = TL;
        break;
    case 2:
        tp = TM;
        break;
    case 3:
        tp = TR;
        break;
    case 4:
        tp = ML;
        break;
    case 5:
        tp = MM;
        break;
    case 6:
        tp = MR;
        break;
    case 7:
        tp = BL;
        break;
    case 8:
        tp = BM;
        break;
    case 9:
        tp = BR;
        break;
    default:
        return;
    }

    // set player choice
    if (table->buffer[tp] == ' ') {
        if (isX) {
            table->buffer[tp] = 'X';
        } else {
            table->buffer[tp] = 'O';
        }
    }

    // switch player
    if (isX) {
        isX = false;
    } else {
        isX = true;
    }
}
