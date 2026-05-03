#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>
#include<string.h>

void modify(int);
void mod_roll(void);
void mod_name(void);

void stud_mod(void){
        if(hptr==0){
                printf("No available entries to modify..\n");
                return;
        }
        char op;
        newline(7);
        stud_print();
        print("       Modify Student Record       \n");
        print("___________________________________\n\n");
        print("R/r      :  Modify by roll number  \n");
        print("N/n      :  Modify by name         \n");
        newline(20);
        printf("Enter your choice : ");
        scanf(" %c",&op);
        switch(op){
                case'R': case'r': mod_roll(); break;

                case'N': case'n': mod_name(); break;

                default: printf("Invalid Choice..\n");
                         printf("Press enter to return to main menu...");
                         getchar();   //To consume newline present in the buffer
                         getchar();   //To detect enter press by user
                         break;
                }
}

void mod_roll(void){
        int rollno;
        printf("Enter roll number of the student:  ");
        scanf(" %d",&rollno);
	modify(rollno);
 }

void mod_name(void){
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

        else if(name_count==1)
                modify((name_print)->roll);
        
	else mod_roll();
}

void modify(int rollno){
	char op;
        st* temp=hptr;
        st* prev=0;
       	while(temp){
                if(temp->roll==rollno){
                newline(19);
		print_onestudent(temp);
		newline(1);
                space(69);
                printf("Modify Name --(1) Modify Percentage --(2)");
                newline(20);
                scanf(" %c",&op);
                if(op=='1'){
                        printf("Enter name : ");
                        scanf(" %[^\n]",temp->name);
                        printf("Name modified successfully...\n");
                        printf("Press enter to continue...");
                        getchar(); getchar();
                        return;
                }
                else if(op=='2'){
                        printf("Enter Percentage : ");
                        scanf(" %f",&temp->percent );
                        printf("Percentage modified successfully...\n");
                        printf("Press enter to continue...");
                        getchar(); getchar();
                        return;
                }
                else{
                         printf("Invalid Choice..\n");
                         printf("Press enter to return to main menu...");
                         getchar();   //To consume newline present in the buffer
                         getchar();   //To detect enter press by user
                         return;
                }
        }
                prev=temp;
                temp=temp->next;
        }
        printf("Invalid Roll Number..\n");
        printf("Press enter to continue....");
        getchar(); getchar();
        return;
 }


