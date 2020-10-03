#ifndef _TABLE_H
#define _TABLE_H

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

struct table {
    char buffer[TABLE_SIZE];
};


void init_table(struct table *table);
void print_table(struct table *table);
void get_input(struct table *table);

#endif
