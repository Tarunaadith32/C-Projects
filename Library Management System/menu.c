#include "func.h"


void print_menu(void){
	system("clear");
	newline(13);
	print("=========================================\n",0);
	space(65);
	printf("|| ****** " BOLD YEL "BOOK MANAGEMENT MENU" RST " ******* ||\n");
	print("=========================================\n",0);
	print("||   [1] Add new book                  ||\n",0);
	print("||   [2] Update book details           ||\n",0);
	print("||   [3] Remove book                   ||\n",0);
	print("||   [4] Search book                   ||\n",0);
	print("||   [5] View all books                ||\n",0);
	print("||   [6] Issue a book                  ||\n",0);
	print("||   [7] Return a book                 ||\n",0);
	print("||   [8] List issued books             ||\n",0);
	print("||   [9] Save                          ||\n",0);
	print("||   [0] Exit                          ||\n",0);
	print("=========================================\n",0);
	newline(2);
}


void print(char* s,int lay){
	if(lay==0){
		int len = strlen(s);
		printf("%*s",(173-len)/2,"");                                                                                                                                          	     printf("%s",s);
	}
	else{
		space(lay);
		printf("%s",s);
	}
}

void clrprint(char*s,char*c,int lay){
	if(lay==0){
		int len = strlen(s);
		printf("%*s",(173-len)/2,"");                                                                                                                                                printf("%s%s%s",c,s,RST);
	}
	else{
		space(lay);
                printf("%s%s%s",c,s,RST);
	}
	return;
}


void newline(int n){
	while(n--)
		printf("\n");
}

void space(int n){
	printf("%*s",n,"");
}
