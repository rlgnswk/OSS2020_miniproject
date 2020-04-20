#include <stdio.h>
#include "base.h"
#include <string.h>

/*
	int id;
  char name[20];
  int age;
  char address[100];
  */

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
void print_all_records(Record records[], int length){
  for(int i = 0 ; i < length ; i ++){
    printf("%d th ===========\n",i);
    printf("id: %d\n",  records[i].id);
    printf("name: %s\n",  records[i].name);
    printf("age: %d\n\n",  records[i].age);
  }
}


// Function: add_a_record()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Leave a brief information about the function
int add_a_record(Record records[], int index){
	// TODO: Modify this function as you need
  printf("add_a_record(): \n\n");
  int id;
  char name[20];
  int age;

  printf("id:");
  scanf("%d", &id);
  if(id <= 0 ){
    printf("smaller than 0 can not be a id\n");
    return index;
    }
  records[index].id = id;

  printf("name:");
  scanf("%s",name);
  strcpy(records[index].name, name);

  printf("age:");
  scanf("%d", &age);
  records[index].age = age;
  
  return index+1;
	
}

int Create_Record(Record records[], int idx){

  char filename[20];
  printf("Target File name: ");
  scanf("%s",filename);
  FILE *f;

  if ((f = fopen(filename, "r")) == NULL) {
        printf("Cannot open the data file!\n");
        return 0;
    }

  int file_len;
  fscanf(f, "%d", &file_len);
  printf("The number of added record: %d\n", file_len);

	for(int i=idx;i<file_len+idx;i++){ 
    fscanf(f,"%d %s %d",&records[i].id,records[i].name, &records[i].age);
  }
	fclose(f);

  return idx + file_len;
}

int Read_File(Record records[]){
  char filename[20];
  printf("Target File name: ");
  scanf("%s",filename);
  FILE *f;

  if ((f = fopen(filename, "r")) == NULL) {
        printf("Cannot open the data file!\n");
        return 0;
    }

  int file_len;
  fscanf(f, "%d", &file_len);
  printf("The number of record: %d\n", file_len);

	for(int i=0;i<file_len;i++){ 
    fscanf(f,"%d %s %d",&records[i].id,records[i].name, &records[i].age);
  }
	fclose(f);
  return file_len;
}

void Save_File(Record records[] , int idx){
  char filename[20];
  printf("Target File name: ");
  scanf("%s",filename);
  
  FILE *f;
  f = fopen(filename, "w");
  fprintf(f,"%d\n",idx);
  for(int i = 0 ; i < idx ; i ++){
    fprintf(f,"%d %s %d\n",records[i].id,records[i].name, records[i].age);
  }
  fclose(f);
}

void Export_txt(Record records[], int idx){
  char filename[20];
  printf("Target File name(.txt): ");
  scanf("%s",filename);
  char txt[10]= ".txt";
  strcat(filename, txt);
  printf("filename:: %s\n", filename);
  
  FILE *f;
  f = fopen(filename, "w");
  fprintf(f,"the number of member: %d\n",idx);
  for(int i = 0 ; i < idx ; i ++){
    fprintf(f,"index: %d\n", i+1);
    fprintf(f,"ID: %d Name: %s Age: %d\n",records[i].id,records[i].name, records[i].age);
  }
  fclose(f);

}


//04.15
void update_member_detail(Record records[], int idx){
  printf("select the wanted index: ");
  int index;
  scanf("%d", &index);
  printf("selected member info: \n");
  printf("id: %d\n",  records[index].id);
  printf("name: %s\n",  records[index].name);
  printf("age: %d\n\n",  records[index].age);

  printf("Update Options\n");
  printf("0: all the information \n");
  printf("1: id \n");
  printf("2: name: \n");
  printf("3: age: \n");
  printf("select update Options: ");
  int option;
  scanf("%d", &option);

  int id;
  char name[20];
  int age;
  if(option == 0){
    printf("update id:");
    scanf("%d", &id);
    records[index].id = id;

    printf("update name:");
    scanf("%s",name);
    strcpy(records[index].name, name);

    printf("update age:");
    scanf("%d", &age);
    records[index].age = age;
  }
  else if(option == 1){
    printf("update id:");
    scanf("%d", &id);
    records[index].id = id;
  }
  else if(option == 2){
    printf("update name:");
    scanf("%s",name);
    strcpy(records[index].name, name);

  }
  else if(option == 3){
    printf("update age:");
    scanf("%d", &age);
    records[index].age = age;
  }
  printf("updated member info: \n");
  printf("id: %d\n",  records[index].id);
  printf("name: %s\n",  records[index].name);
  printf("age: %d\n\n",  records[index].age);
}

void delete_member(Record records[], int idx){
  printf("0: delete one records 1: delete all record:");
  int option;
  scanf("%d",&option);
  if(option == 0){
    printf("select the wanted index: ");
    int index;
    scanf("%d", &index);
    printf("selected member info: \n");
    printf("id: %d\n",  records[index].id);
    printf("name: %s\n",  records[index].name);
    printf("age: %d\n\n",  records[index].age);

    printf("Is right member to delete?\n");
    printf("0: No , 1: Yes ");
    int option;
    scanf("%d", &option);
    if(option == 0 )printf("Cancel \n");
    else if(option == 1){

      records[index].id = 0;
      strcpy(records[index].name, "\0");
      records[index].age = 0;

    }
    else printf("Wrong option\n");
  }
  else if(option == 1){
    printf("Are you sure? 0:No, 1:Yes ");
    scanf("%d",&option);
    if(option == 1){
      for(int i = 0 ; i < idx ; i ++){
        records[i].id = 0;
        strcpy(records[i].name, "\0");
        records[i].age = 0;
      }
    }
    else printf("Cancel.\n");
  }
  else printf("Cancel.\n");
}



// TODO: Add more functions to fulfill the requirements