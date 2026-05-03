#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>

st* hptr=0;
int rollno=1;

void read_data(void){
	FILE* fp=fopen("student.dat","rb");
	if(fp==NULL)
		return;
	while(1){
 		st* temp=(st*)malloc(sizeof(st));
       	       	if(fread(temp,sizeof(st),1,fp)!=1) {
		       free(temp);
	       		break;
		}		
       	       	if(hptr==0){
            		 hptr=temp;
                	 temp->next=0;
			 rollno=(temp->roll)+1;
               	}
               	else
               	{	
               	        st* end=hptr;
               	        while(end->next)
               	        	end=end->next;
               	        end->next=temp;
               	        temp->next=0;
			rollno=(temp->roll)+1;
              		}		
		}
}


