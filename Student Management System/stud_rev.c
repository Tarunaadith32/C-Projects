#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>
#include<string.h>

void stud_rev(void){
	
	st* temp=(st*)malloc(sizeof(st));
	int i=0,j=0,count=0,size=sizeof(st)-sizeof(st*);
	st* end=hptr;
	
	while(end){
		++count;
		end=end->next;
	}
	
	end=hptr;
	st** node=(st**)malloc(count*sizeof(st*));
	
	for(i=0;i<count;i++){ 
		node[i]=end;
		end=end->next;
	}
	for(i=0,j=count-1;i<j;i++,j--){
		memcpy(temp,node[i],size);
		memcpy(node[i],node[j],size);
		memcpy(node[j],temp,size);
	}
	
	printf("Data reversed successfully..\n");
	printf("Press enter to continue... ");
	getchar();
	getchar();
	stud_show();
	return;
	
}
