#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>
#include<string.h>

void delete(st*,st*);
void del_roll(void);
void del_name(void);

void stud_del(void){
	if(hptr==0){
		printf("No available entries to delete..\n");
		return;
	}
	char op;
	newline(7);
	stud_print();
	print("       Delete Student Record       \n");
	print("__________________________________\n\n");
	print("R/r	:  Delete by roll number \n");
	print("N/n	:  Delete by name        \n");
	newline(20);
	printf("Enter your choice : ");
	scanf(" %c",&op);
	switch(op){
		case'R': case'r': del_roll(); break;
	 
		case'N': case'n': del_name(); break;
	       
	       	default: printf("Invalid Choice..\n");
             	         printf("Press enter to return to main menu...");
                	 getchar();   //To consume newline present in the buffer
                         getchar();   //To detect enter press by user
                         break;		  
		}	
	}	

void delete(st* temp,st* prev){
	 if(prev==0&&(temp->next==0)){
	  hptr=0;
	  }
	 else if(prev==0){
		 hptr=temp->next;
	  }
	 else{
		prev->next=temp->next;
	  }
	free(temp);
	return;
}

void del_roll(void){
	int rollno; char op;
        printf("Enter roll number of the student:  ");
        scanf(" %d",&rollno);
        st* temp=hptr;
        st* prev=0;
        while(temp){
        	if(temp->roll==rollno){
                newline(19);
		print_onestudent(temp);
                newline(2);
                space(69);
                printf("Confirm delete? (y/n)");
                newline(20);
                scanf(" %c",&op);
                if(op=='y'||op=='Y') delete(temp,prev);
                return;
                }
     	        prev=temp;
                temp=temp->next;
	}
	printf("Invalid Roll Number..\n");
	printf("Press enter to continue....");
	getchar(); getchar();
	return;
 }

void del_name(void){
	char op,s[20];
	int name_count=0;
	st* name_print;
        printf("Enter name :  ");
        scanf(" %[^\n]",s);
        st* temp=hptr;
        while(temp){
                if(strcmp(s,(temp->name))==0){
			name_count++;
			if(name_count==1) {
				name_print=temp;
				print_onestudent(temp);
			}
			else{
	                        space(69);
        	                printf("%-5d",temp->roll);
                	        space(3);
                	        printf("%-20s",temp->name);
                	        space(3);
                	        printf("%-6.2f",temp->percent);
                	        printf("\n");
			}	
        	}
               	temp=temp->next;
	}
	int rollno;
	if(name_count==0){
		printf("Name not found...\n");
		printf("Press enter to continue..");
		getchar();
		getchar();
		return;
	}
	else if(name_count==1){
		rollno=(name_print)->roll;
		newline(19);
	        temp=hptr;
        	st* prev=0;
		while(temp){
                if(temp->roll==rollno){
                newline(19);
                print_onestudent(temp);
                newline(2);
                space(69);
                printf("Confirm delete? (y/n)");
                newline(20);
                scanf(" %c",&op);
                if(op=='y'||op=='Y') delete(temp,prev);
                return;
                }
                prev=temp;
                temp=temp->next;
        	}	
	}	
	else del_roll();
}
