#include "func.h"

void show(void){
	system("clear");
	newline(11);
	print("===============================================================================\n",0);
	space(46);
	printf("||****************************** " YEL BOLD "LIST OF BOOKS" RST " ******************************||\n");
	print("===============================================================================\n",0);
	
	if(bookptr==0){
	print("||                            NO BOOKS AVAILABLE                             ||\n",0);
	print("===============================================================================\n",0);
	newline(1);
	}
	
	else{
		space(46);
		printf("||"G BOLD" BOOK ID "RST"|     "G BOLD"      BOOK TITLE      "RST"       |   "G BOLD"    AUTHOR   "RST"    |"G BOLD"  COUNT "RST" ||\n");
		print("===============================================================================\n",0);
		book *temp=bookptr;
		while(temp){		
		space(46);
        	printf("||  %-4u   | %-33s| %-19s|   %-4u  ||\n",temp->bookid,temp->title,temp->author,temp->count );
		temp=temp->next;
		}
		print("===============================================================================\n",0);
		newline(1);
	}
}
