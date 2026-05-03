#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>

void delete_nodes(void);

void stud_exit(void){
	char op;
	newline(11);
	print("       Exit the program      \n");
	print("_____________________________\n\n");
	print(" S/s   :  Save and exit      \n");
	print(" E/e   :  Exit without saving\n");
	print(" C/c   :  Cancel and go back \n");
	newline(25);
	printf("Enter your choice  : ");
	scanf(" %c",&op);
	switch(op){
		case 'S': case 's': stud_save();delete_nodes(); printf("Exitting...\n"); exit(1);
		case 'E': case 'e': delete_nodes();printf("Exitting...\n"); exit(1);
		case 'C': case 'c': return;
				    
	}
}

void delete_nodes(void){
	st* temp;
	while(hptr){
	temp=hptr;
	hptr=hptr->next;
	free(temp);
	}
	temp=NULL;

}
