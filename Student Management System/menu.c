//42,173
#include<stdio.h>
#include<string.h>
#include "menu.h"

char menu(void){
	newline(12);
	print("   ***STUDENT RECORD MENU***    \n");
	print("________________________________\n\n");
	print("A/a     : Add New Record        \n");
	print("D/d     : Delete a Record       \n");
	print("S/s     : Show the List         \n");
	print("M/m     : Modify a record       \n");
	print("T/t     : Sort the List         \n");
	print("R/r     : Reverse the List      \n");
	print("L/l     : Delete all the Records\n");
	print("V/v     : Save                  \n");
	print("E/e     : Exit                  \n");
	
	newline(19);

	
	char op;
	printf("Enter your choice :  ");
	scanf(" %c",&op);
	return op;
}

void print(const char* s){
	int sp=(173-strlen(s))/2;
	space(sp);
	printf("%s",s);
}

void newline(int nl){
	for(nl;nl;nl--)
		printf("\n");
	return;
}

void space(int sp){
	printf("%*s",sp,"");
	return;
}
