#include "func.h"

book* bookptr=0;
issue* issueptr=0;
unsigned int bookid;
unsigned int issueid;

void read(){
	FILE* fp=fopen("booklist.csv","r");
	if(fp==NULL){
		bookid=1000;
	}
	else{	
		char s[100];
		book *temp,*end;
		while(fgets(s,100,fp)!=NULL){		
			
			temp=(book*)malloc(sizeof(book));
			sscanf(s,"%u,%[^,],%[^,],%u\n",&temp->bookid,temp->title,temp->author,&temp->count);
			
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
		bookid=temp->bookid+1;
		}
	fclose(fp);
	}

        fp=fopen("issuelist.csv","r");
        if(fp==NULL){
                issueid=1;
        }
        else{
                char s[100];
                issue *temp1,*end1;
                while(fgets(s,100,fp)!=NULL){

                        temp1=(issue*)malloc(sizeof(issue));
                        sscanf(s,"%u,%u,%u,%[^,],%[^,],%[^,],%[^,],%ld,%d",&temp1->issueid,&temp1->bookid,&temp1->userid,temp1->name,temp1->issuedate,temp1->duedate,temp1->returndate,&temp1->duecode,&temp1->fine);

                        if(issueptr==0){
                                issueptr=temp1;
                                temp1->prev=0;
                                temp1->next=0;
                        }
                        else{
                                end1=issueptr;
                                while(end1->next) end1=end1->next;
                                end1->next=temp1;
                                temp1->prev=end1;
                                temp1->next=0;
                        }
		issueid=temp1->issueid+1;
                }
	fclose(fp);
        }
}
