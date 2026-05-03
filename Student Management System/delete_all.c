#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>

void delete_all(){
	while(hptr){
		st*next=hptr->next;
		free(hptr);
		hptr=next;
	}
	rollno=0;
	printf("All data cleared.....\n");
	printf("Press enter to continue...\n");
	getchar(); getchar();
	return;
}
