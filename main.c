#include <stdio.h>
#include <string.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];
	char user_input[64] = "";
	while(strcmp(user_input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
    getchar();
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
int idx = 0;
int p = 0;
void input_handler(char input[], Record records[]){

	// TODO: Modify this function as you need
  
  
	if(!strcmp(input, "1"))
		idx = Create_Record(records, idx);
	else if(!strcmp(input, "2"))
		idx = Read_File(records);	
	else if(!strcmp(input, "3"))
    Save_File(records, idx);
	else if(!strcmp(input, "4")){
    idx = add_a_record(records, idx);
    
    printf("index: %d\n", idx);
  }	
  else if(!strcmp(input, "5")){
    
    printf("how many do you want to show?\n");
    printf("(0: all , other numbers to show)");
    char po = getchar();
    int p = po - '0';
    printf("selected option : %d\n", p);
    if(p == 0)print_all_records(records, idx);
    else print_all_records(records, p);
  }
  else if(!strcmp(input, "6"))	
    Export_txt(records, idx);
  else if(!strcmp(input, "7"))
    update_member_detail(records, idx);
  else if(!strcmp(input, "8"))
    delete_member(records, idx);
  else if(!strcmp(input, "9"))
    search_member(records, idx);
  else if(!strcmp(input, "10")){
    idx = Optimize_records(records, idx);
  }
  else if(!strcmp(input, "11"))
    Member_statistics(records, idx);
  else if(!strcmp(input, "12"))
    sort_records(records, idx);
	else if(!strcmp(input, "99"))
		printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
    
}



// Function: display_menu()
// Input: none
// Output: none
// - Leave a brief information about the function
void display_menu(){

	// TODO: Modify this function as you need

	printf("******************************\n");
	printf(" Membership management system \n");
	printf("******************************\n");
  printf(" 1. Create(Add) Record from File\n");
	printf(" 2. Read File\n");
  printf(" 3. Save File\n");
	printf(" 4. Add a new member\n");
	printf(" 5. Print member info\n");
  printf(" 6. Export records as .txt file \n");
  printf(" 7. Update member information \n");
  printf(" 8. Delete member information \n");
  printf(" 9. Search the members information \n");
  printf(" 10. Optimize (defragment) the records\n");
	printf(" 11. Member statistics\n");
  printf(" 12. Sort the Records\n");
	printf(" 99. Quit\n");

}