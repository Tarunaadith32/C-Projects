#include "func.h"

void book_search(void){

	char op;
	char s[50];
	int choice;
	book* temp;
	system("clear");
	newline(11);
	print("=============================\n",0);
	space(71);
       printf("||*****"YEL BOLD" SEARCH A BOOK "RST"*****||\n");
	print("=============================\n",0);
	print("||    [1]-- By Book ID     ||\n",0);
	print("||    [2]-- By Book Title  ||\n",0);
	print("||    [3]-- By Author      ||\n",0);
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
			       newline(1);
			       print("Book found...",46);
			       newline(2);
			       return;
	
		case ('2'):	print("Enter Book Name : ",71);
				scanf(" %[^\n]",s);
				temp=bookptr;
       				while((temp!=0)&&(strcmp(s,temp->title)!=0)) temp=temp->next;	
				if(temp==0){
				       	print("Book not found..",71);
					newline(2);
					return;
				}
				else{
					bookprint(temp);
                               		newline(1);
                               		print("Book found...",46);
                               		newline(2);
                               		return;		
				}

		case ('3'):	print("Enter Author Name : ",71);
				int flag=0; 
				scanf(" %[^\n]",s);
				temp=bookptr;
				
				while(temp!=0){
				
					if(strcmp(s,(temp->author))==0){	
						flag++;
						if(flag==1){
					       		system("clear");
       							newline(11);
       							print("===============================================================================\n",0);
       							space(46);
       							printf("||"G BOLD" BOOK ID "RST"|     "G BOLD"      BOOK TITLE      "RST"       |   "G BOLD"    AUTHOR   "RST"    |"G BOLD"  COUNT "RST" ||\n");
       							print("===============================================================================\n",0);
						
						}
				   		space(46);
      	 			       		printf("||  %-4u   | %-33s| %-19s|   %-4u  ||\n",temp->bookid,temp->title,temp->author,temp->count );
					}
				       		temp=temp->next;
					}
				if(flag>0){
					print("===============================================================================\n",0);
					newline(1);
					return;
				}
				else{
					print("Book not found...",71);
					newline(1);
					return;
				}

		default: return;		
					

						
						       
	}
				       
}

