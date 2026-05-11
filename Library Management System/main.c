#include "func.h"

int main(void){
	read();
	char op;
	while(1){	
		print_menu();
		print("Enter Your Choice : ",65);
		scanf(" %c",&op);
		switch(op){
			
			case '0': print("Press enter to exit..",65); getchar();getchar(); system("clear"); return 0;
			
			case '1': add(); print("Press enter to return to main menu..",64); getchar();getchar(); system("clear"); break;
			
			case '2': update(); print("Press enter to return to main menu..",0); getchar();getchar(); system("clear"); break;
			
			case '3': book_remove(); print("Press enter to return to main menu..",0); getchar();getchar(); system("clear"); break;
			
			case '4': book_search(); print("Press enter to return to main menu..",0); getchar();getchar(); system("clear"); break;
			
			case '5': show(); print("Press enter to return to main menu..",46); getchar();getchar(); system("clear"); break;
			
			case '6': book_issue(); print("Press enter to return to main menu..",0); getchar();getchar(); system("clear"); break;
			
			case '7': book_return(); print("Press enter to return to main menu..",45); getchar();getchar(); system("clear"); break;
			
			case '8': issue_display(); print("Press enter to return to main menu..",19); getchar();getchar(); system("clear"); break;
			
			case '9': save(); print("Press enter to return to main menu..",65); getchar();getchar(); system("clear"); break;

		}
	}
}

