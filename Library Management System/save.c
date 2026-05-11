#include "func.h"

void save(){
	FILE* fp=fopen("booklist.csv","w");
	book* temp=bookptr;
	while(temp){
		fprintf(fp,"%u,%s,%s,%u\n",temp->bookid,temp->title,temp->author,temp->count);
		temp=temp->next;
	}
	fclose(fp);

	fp=fopen("issuelist.csv","w");
	issue* temp1=issueptr;
        while(temp1){
                fprintf(fp,"%u,%u,%u,%s,%s,%s,%s,%ld,%d\n",temp1->issueid,temp1->bookid,temp1->userid,temp1->name,temp1->issuedate,temp1->duedate,temp1->returndate,temp1->duecode,temp1->fine);
                temp1=temp1->next;
        }
        fclose(fp);
	
	system("clear");
	newline(13);
	print("Data Saved Successfully...\n",65);
	newline(1);
	
}
