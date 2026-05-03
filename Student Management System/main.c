#include <stdio.h>
#include "menu.h"
#include "func.h"
#include<unistd.h>

int main(){
	char op;	
	read_data();
	while(1){
		op=menu();
		switch(op){
			
			case 'A': case 'a': stud_add(); break;
			
			case 'S': case 's': stud_show(); break;

			case 'D': case 'd': stud_del(); break;

			case 'L': case 'l': delete_all(); break;
			
			case 'M': case 'm': stud_mod(); break;
			
			case 'T': case 't': stud_sort(); break;
		
			case 'R': case 'r': stud_rev(); break;

			case 'V': case 'v': stud_save(); 
					    printf("Press enter to go to main menu..");
        				    getchar(); getchar();
					    break;		    
			
			case 'E': case 'e': stud_exit(); break; 
			
			default: printf("Invalid Choice..\n");
				 printf("Press enter to return to main menu...");
				 getchar();   //To consume newline present in the buffer
				 getchar();   //To detect enter press by user
				 break; 
		}
	} 
	return 0;
}
