#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>

void stud_save(){
	FILE* fp=fopen("student.dat","wb");
	if(fp==NULL){
		printf("file open failed..\n");
		return;
	}
	st* temp=hptr;
	if(temp==0){
	       fclose(fp);
       	       return;
	}
	while(temp!=0){
		if(fwrite(temp,sizeof(st),1,fp)!=1){
			printf("Write failed...\n");
			return;
		}
		temp=temp->next;
	}
	fclose(fp);
	printf("Data saved successfully..\n");
}
