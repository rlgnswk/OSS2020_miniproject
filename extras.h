#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
//int defragment(Record[]);
//void display_stats(Record[]);

int Optimize_records(Record records[], int idx);

void Member_statistics(Record records[], int idx);

void sort_records(Record records[], int idx);

void search_member(Record record[], int idx);

#endif