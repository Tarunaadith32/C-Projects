#include "func.h"

void add(void){
	char op;
	do{
	system("clear");
	newline(13);
	print("===========================================\n",0);
	space(64);
	printf("|| ************ " BOLD YEL "Add New Book" RST " *********** ||\n");
	print("===========================================\n",0);
	book* temp,*end;
		temp=(book*)malloc(sizeof(book));
		temp->bookid=bookid++;
		newline(1);
		print("Book name   : ",64);
		scanf(" %[^\n]",temp->title);
		newline(1);
		print("Author name : ",64);
		scanf(" %[^\n]",temp->author);
		newline(1);
		print("Count       : ",64);
		scanf(" %u",&temp->count);
		newline(1);
		if(bookptr==0){
                	bookptr=temp;
                        temp->prev=0;
                        temp->next=0;
               	        }
                else{
                        end=bookptr;
                        while(end->next) end=end->next;
                        end->next=temp;
                        temp->prev=end;
                        temp->next=0;
                        }
		space(64);
		printf("Added book with id %d Successfully\n",bookid-1);
		newline(1);
		print("Add another book ? ... [y/n] ",64);
		scanf(" %c",&op);
		newline(1);
	}while(op=='Y'||op=='y');
	return;
}






	

		
