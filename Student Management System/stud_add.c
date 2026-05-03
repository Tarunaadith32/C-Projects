#include<stdio.h>
#include "menu.h" 
#include "func.h"
#include<stdlib.h>


void stud_add(void){
	char op;
	do{
		st* temp=(st*)malloc(sizeof(st));
		printf("Enter student name : ");
		scanf(" %[^\n]",temp->name);
		printf("Percentage :");
		scanf(" %f",&temp->percent);
		newline(1);
		if(hptr==0){
			hptr=temp;
			temp->next=0;
		}
		else 
		{
			st* end=hptr;
			while(end->next)
				end=end->next;
			end->next=temp;
			temp->next=0;
		}
		temp->roll=rollno++;
		printf("Added Successfully..\n");
		printf("Add more? (y/n)");
		scanf(" %c",&op);
	}while(op=='y'||op=='Y');
	printf("Press enter to return to main menu...");
	getchar();	// To consume newline in buffer
	getchar();
	return;
}

