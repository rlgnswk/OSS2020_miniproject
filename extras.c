#include <stdio.h>
#include "extras.h"
#include <string.h>



int Optimize_records(Record records[], int idx){

  int count = 0;
  for(int i = 0 ; i < idx ; i ++){
    if(records[i].id == 0 && records[i].age == 0){
      for(int j = i+1 ; j < idx - count ; j++){
        records[j-1].id = records[j].id;
        strcpy(records[j-1].name , records[j].name);
        records[j-1].age = records[j].age;
      }
      count++;
    }
  }

  printf("%d defragment done\n", count);
  printf("index size %d -> %d\n",idx, idx - count);
  return idx - count;
}

void Member_statistics(Record records[], int idx){
  int sum_of_age = 0;
  int mean_of_age = 0;

  for(int i = 0 ; i < idx ; i ++){
    sum_of_age += records[i].age;
  }
  printf("the number of member : %d\n", idx);
  printf("mean_of_age: %d\n", sum_of_age/(idx));

}

void sort_records(Record records[], int idx){

    printf("sort option 0: id , 1: age, 2:Cancel\n");
    int option;
    printf("wanted option:");
    scanf("%d",&option);
    Record temp;
    if(option == 0){
        printf("sorted by id\n");
        for(int i = 0 ; i < idx-1 ; i++){
          for(int j = i+1 ; j < idx ; j++){
            if(records[i].id < records[j].id){
              temp = records[j];
              records[j] = records[i];
              records[i] = temp;
            }
          }
        }
    }
    else if(option == 1){
        printf("sorted by age\n");
        for(int i = 0 ; i < idx-1 ; i++){
          for(int j = i+1 ; j < idx ; j++){
            if(records[i].age < records[j].age){
              temp = records[j];
              records[j] = records[i];
              records[i] = temp;
            }
          }
        }
    } 
    else{
      printf("Cancel the sortion process\n");
    }
}


void search_member(Record records[], int length){
  printf("select search option:\n");
  printf("0: Search \n");
  printf("99: cancel \n");
  printf("select update Options: ");
  int option;
  scanf("%d", &option);
  
  int id;
  char name[20];
  int age;

  if(option==0){
    printf("Name: ");
    scanf("%s",name);
    printf("Age: ");
    scanf("%d", &age);
    
    for(int i=0;i<length;i++){
      if(strncmp(records[i].name,name,strlen(name))==0){
        if(records[i].age==age){
          printf("\n******After Searching******\n");
          printf("id: %d\n", records[i].id);
          printf("name: %s\n", records[i].name);
          printf("age: %d\n\n", records[i].age);
        }
      }
      else
      printf("No data\n");
    
    }
  if(option==99) {
    printf("Cancel searching \n");
  }
}
 
//<<<<<<< develop
}
 
=======
void delete_all_but(Record records[], int length){
  int t_age;
  printf("Delete all records that are not the age.\n");
  printf("Enter a age: ");
  scanf("%d",&t_age);
  for(int i=0;i<length;i++){
    if(records[i].age!=t_age){
        records[i].id = 0;
        strcpy(records[i].name, "\0");
        records[i].age = 0;
    }
  }
  printf("Complete.\n");
}
// TODO: Add more functions to fulfill the optional requirements
//>>>>>>> master
