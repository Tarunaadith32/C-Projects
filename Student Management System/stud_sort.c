#include<stdio.h>
#include"func.h"
#include"menu.h"
#include<stdlib.h>
#include<string.h>
#include <ctype.h>

void sort_roll(void);
void sort_name(void);
void sort_percent(void);

int compare(char*,char*);

void stud_sort(){
	if(hptr==0){
                printf("No available entries to sort..\n");
		printf("Press enter to return to main menu...");
                getchar();   //To consume newline present in the buffer      
		getchar();   //To detect enter press by user
                return;
        }
	newline(15);
	print("      Sort Student Records      \n");
        print("________________________________\n\n");
        print("R/r      :  Sort by roll number \n");
        print("N/n      :  Sort by name        \n");
        print("P/p      :  Sort by percentage  \n");
        newline(20);
        char op;
	printf("Enter your choice : ");
        scanf(" %c",&op);
        switch(op){
                case'R': case'r': sort_roll(); break;

                case'N': case'n': sort_name(); break;
                
		case'P': case'p': sort_percent(); break;

                default: printf("Invalid Choice..\n");
                         printf("Press enter to return to main menu...");
                         getchar();   //To consume newline present in the buffer
                         getchar();   //To detect enter press by user
                         break;
                }
        }


void sort_roll(void){
	int count=0,i,j;
	st* temp=hptr;
	int size=sizeof(st)-sizeof(st*);
	st *swap= (st*)malloc(sizeof(st));
	
	while(temp){
		count++;
		temp=temp->next;
	}
	st** node=(st**)malloc(count*sizeof(st*));
	temp=hptr;
	
	for(i=0;i<count;i++){
		node[i]=temp;
		temp=temp->next;
	}
	temp=hptr;

	for(i=1;i<count;i++){
		for(j=i;j>0;j--){
			if((node[j]->roll)>=(node[j-1]->roll)) break;
			memcpy(swap,node[j],size);
	                memcpy(node[j],node[j-1],size);
        	        memcpy(node[j-1],swap,size);
		}
	}
	hptr=node[0];
	printf("Sort successful..\n");
	free(node);
	free(swap);
	node=NULL;swap=NULL;
	printf("Press enter to continue....\n");
	getchar(); getchar();
	stud_show();
	return;
}

void sort_percent(void){
        int count=0,i,j;
        st* temp=hptr;
        int size=sizeof(st)-sizeof(st*);
        st* swap=(st*)malloc(sizeof(st));

        while(temp){
                count++;
                temp=temp->next;
        }
        st** node=(st**)malloc(count*sizeof(st*));
        temp=hptr;

        for(i=0;i<count;i++){
                node[i]=temp;
                temp=temp->next;
        }
        temp=hptr;

        for(i=1;i<count;i++){
                for(j=i;j>0;j--){
                       if((node[j]->percent)<(node[j-1]->percent)) break;
                        memcpy(swap,node[j],size);
                        memcpy(node[j],node[j-1],size);
                        memcpy(node[j-1],swap,size);
                }

        }
	hptr=node[0];
        free(node);
        free(swap);
        node=NULL;swap=NULL;
	
        printf("Sort successful..\n");
        printf("Press enter to continue....\n");
        getchar();
	getchar();
        stud_show();
        return;
}




void sort_name(void){
        int count=0,i,j;
        st* temp=hptr;
        int size=sizeof(st)-8;
        st* swap=(st*)malloc(sizeof(st));

        while(temp){
                count++;
                temp=temp->next;
        }
        st** node=(st**)malloc(count*sizeof(st*));
        temp=hptr;

        for(i=0;i<count;i++){
                node[i]=temp;
                temp=temp->next;
        }
        temp=hptr;

        for(i=1;i<count;i++){
                for(j=i;j>0;j--){
                        if(compare((node[j]->name),(node[j-1]->name))>=0) break;
                        memcpy(swap,node[j],size);
                        memcpy(node[j],node[j-1],size);
                        memcpy(node[j-1],swap,size);
                }
        }
	hptr=node[0];
        free(node);
        free(swap);
        node=NULL;swap=NULL;
        printf("Sort successful..\n");
        printf("Press enter to continue....\n");
        getchar(); getchar();
        stud_show();
        return;
}

int compare(char *n1,char *n2){
	char s1[20],s2[20];
	int i=0;
	while(*(n1+i)){
		*(s1+i)=tolower(*(n1+i));
		i++;}
	s1[i]='\0';
	
	i=0;
	while(*(n2+i)){
		*(s2+i)=tolower(*(n2+i));
		i++;
	}
	s2[i]='\0';
	return strcmp(s1,s2);	
} 
