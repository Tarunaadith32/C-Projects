#include "func.h"


void update(void){
	char op;
	int choice;
	book* temp;
	system("clear");
	newline(11);
	print("=============================\n",0);
	space(71);
       printf("||**"YEL BOLD" UPDATE BOOK DETAILS "RST"**||\n");
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
       			       print("   [1]--Update Book Title    [2]--Update Author Name     [3]--Update Count : ",46);
			       scanf(" %d",&choice);
			       newline(1);
			       if(choice==1){
				       print("Enter Title : ",46);
				       scanf(" %[^\n]",temp->title);
			       }
			       else if(choice==2){
				       print("Enter Author Name : ",46);
				       scanf(" %[^\n]",temp->author);
			       }
			       else if(choice==3){
				       print("Enter Count : ",46);
				       scanf(" %u",&temp->count);
			       }
			       else{
				       print("Invalid Choice..\n",46);
				       newline(1);
				       return;
			       }
			       newline(1);
			       print("Book Updated Successfully...",46);
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
			       		print("   [1]--Update Book Title    [2]--Update Author Name     [3]--Update Count : ",46);
                               		scanf(" %d",&choice);
                               		newline(1);
                             		if(choice==1){
                                        	print("Enter Title : ",46);
                                        	scanf(" %[^\n]",temp->title);
                               		}
                               		else if(choice==2){
                                       		print("Enter Author Name : ",46);
                                       		scanf(" %[^\n]",temp->author);
                               		}
                               		else if(choice==3){
                                       		print("Enter Count : ",46);
                                       		scanf(" %u",&temp->count);
                               		}
                               		else{
                                       		print("Invalid Choice..\n",46);
                                       		newline(1);
                                       		return;
                               		}
                               		newline(1);
                               		print("Book Updated Successfully...",46);
                               		newline(2);
                               		return;		
				}
						       
	}
				       
}

void bookprint(book* temp){
       system("clear");
       newline(11);
       print("===============================================================================\n",0);
       space(46);
       printf("||"G BOLD" BOOK ID "RST"|     "G BOLD"      BOOK TITLE      "RST"       |   "G BOLD"    AUTHOR   "RST"    |"G BOLD"  COUNT "RST" ||\n");
       print("===============================================================================\n",0);
       space(46);
       printf("||  %-4u   | %-33s| %-19s|   %-4u  ||\n",temp->bookid,temp->title,temp->author,temp->count );
       print("===============================================================================\n",0);
       newline(1);
	
}

