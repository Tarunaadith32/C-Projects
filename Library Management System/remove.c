#include "func.h"

void book_remove(void){

	char op;
	int choice;
	book* temp;
	system("clear");
	newline(11);
	print("=============================\n",0);
	space(71);
       printf("||*****"YEL BOLD" REMOVE A BOOK "RST"*****||\n");
	print("=============================\n",0);
	print("||    [1]-- By Book ID     ||\n",0);
	print("||    [2]-- By Book Title  ||\n",0);
	print("||    [0]-- Main Menu      ||\n",0);
	print("=============================\n",0);
	newline(1);
	
	print("Enter your choice : ",71);
	scanf(" %c",&op);
	switch(op){
		case ('0'): return;

		case ('1'):    print("Enter Book ID : ",71);
			       temp=bookptr;
			       unsigned int id;
			       scanf(" %u",&id);
       				while((temp!=0)&&((temp->bookid)!=id)) temp=temp->next;
       				if(temp==0){
	       			print("Book not found..",71);
	       			newline(2);
	       			return;
       				}
			       bookprint(temp);
       			       print("        [1]--CONFIRM REMOVE        [2]--GO BACK TO MAIN MENU : ",46);
			       scanf(" %d",&choice);
			       newline(1);
			       if(choice==1){
			       		if(temp->prev!=0&&temp->next!=0){
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
						free(temp);
					}
					else if(temp->prev==0&&temp->next==0){
						free(temp);
						bookptr=0;
					}
					else if(temp->prev==0){
						temp->next->prev=0;
						bookptr=temp->next;
						free(temp);
					}
					else{
						temp->prev->next=0;
						free(temp);
					}
			       }
			       else{
				       return;
			       }
			       newline(1);
			       print("Book Removed Successfully...",46);
			       newline(2);
			       return;
	
		case ('2'):	print("Enter Book Name : ",71);
				char s[50];
				scanf(" %[^\n]",s);
				temp=bookptr;
       				while((temp!=0)&&(strcmp(s,(temp->title))!=0)) temp=temp->next;	
				if(temp==0){
				       	print("Book not found..",71);
					newline(2);
					return;
				}
				else{
					bookprint(temp);
			       		print("        [1]--CONFIRM REMOVE        [2]--GO BACK TO MAIN MENU : ",46);
                               scanf(" %d",&choice);
                               newline(1);
                               if(choice==1){
                                        if(temp->prev!=0&&temp->next!=0){
						temp->prev->next=temp->next;
						temp->next->prev=temp->prev;
                                                free(temp);
                                        }
                                        else if(temp->prev==0&&temp->next==0){
                                                free(temp);
                                                bookptr=0;
                                        }
                                        else if(temp->prev==0){
                                                temp->next->prev=0;
                                                bookptr=temp->next;
                                                free(temp);
                                        }
                                        else{
                                                temp->prev->next=0;
                                                free(temp);
                                        }

                               		}
                               		else{
                                       		print("Invalid Choice..\n",46);
                                       		newline(1);
                                       		return;
                               		}
                               		newline(1);
                               		print("Book removed Successfully...",46);
                               		newline(2);
                               		return;		
				}
						       
	}
				       
}

