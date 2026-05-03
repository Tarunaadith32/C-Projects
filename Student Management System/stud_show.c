#include<stdio.h>
#include "func.h"
#include "menu.h"


void stud_show(void){

		newline(11);
		print("      ***EXISTING STUDENT RECORD ***      \n");
		print("__________________________________________\n");
	if(hptr==0){
		printf("\n");
		print("           No records available!          \n\n");
		print("__________________________________________");
		newline(27);
                printf("Press enter to return to main menu...");
                getchar(); getchar();
	}

	else{
		int count=0;
		print(" ROLL NO |         NAME         | PERCENT \n");
		print("__________________________________________\n");
		st* end=hptr;
		while(end!=0){
			space(69);
			printf("%-5d",end->roll);
			space(3);
			printf("%-20s",end->name);
			space(3);
			printf("%-6.2f",end->percent);
			printf("\n");
			end=end->next;
			count++;
		}
			newline(30-count);
                        printf("Press enter to return to main menu...\n");
                        getchar();
			return;
	}
}

void stud_print(void){
		int count=0;
		newline(1);
	        print(" ROLL NO |         NAME         | PERCENT \n");
                print("__________________________________________\n");
                st* end=hptr;
                while(end!=0){
                        space(69);
                        printf("%-5d",end->roll);
                        space(3);
                        printf("%-20s",end->name);
                        space(3);
                        printf("%-6.2f",end->percent);
                        printf("\n");
			count++;
                        end=end->next;
		}
		newline(8-count);	
                }


void print_onestudent(st* temp){
	                        print(" ROLL NO |         NAME         | PERCENT \n");
                        print("__________________________________________\n");
                        space(69);
                        printf("%-5d",temp->roll);
                        space(3);
                        printf("%-20s",temp->name);
                        space(3);
                        printf("%-6.2f",temp->percent);
                        printf("\n");
}

