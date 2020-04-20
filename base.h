#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"
//04.08
void Export_txt(Record record[], int idx);

int Create_Record(Record records[], int idx);

int Read_File(Record records[]);

void Save_File(Record record[], int idx);

//04.15
void update_member_detail(Record record[], int idx);

void delete_member(Record record[], int idx);






// function prototypes
void print_all_records(Record Record[], int length);

int add_a_record(Record Record[], int index);


#endif