#include "func.h"

void book_issue(void){
	system("clear");
	newline(11);
        print("=====================================\n",0);
        space(67);
       printf("|| *********"YEL BOLD" ISSUE A BOOK "RST"******** ||\n");
        print("=====================================\n",0);
	newline(2);
	print("Enter Book ID : ",68);
        
        book* temp;	
	temp=bookptr;
        unsigned int id;
        scanf(" %u",&id);
        while((temp!=0)&&((temp->bookid)!=id)) temp=temp->next;

	if(temp==0){
        	print("Book not found..",68);
                newline(2);
                return;
	}
	if(temp->count==0){
		print("Book not available..",68);
		newline(2);
		return;
	}


	issue* temp1=(issue*)malloc(sizeof(issue));
	temp1->issueid=issueid++;
	temp1->bookid=id;
	newline(1);

	print("Enter user ID: ",68);
	scanf(" %u",&temp1->userid);
	newline(1);

	print("Enter user name: ",68);
	scanf(" %[^\n]",temp1->name);
	newline(1);

	long currdate,duedate;
	struct tm *curr,*due;

	currdate=time(NULL);
	duedate = currdate+ (3600*24*7);
	temp1->duecode=duedate;

	curr=localtime(&currdate);
	strftime(temp1->issuedate,sizeof(temp1->issuedate),"%d %b %Y",curr);

	due= localtime(&duedate);
	strftime(temp1->duedate,sizeof(temp1->duedate),"%d %b %Y",due);


	strcpy(temp1->returndate,"-");

	temp1->fine=0;

        if(issueptr==0){
		issueptr=temp1;
                temp1->prev=0;
                temp1->next=0;
                }
        else{
                issue* end1=issueptr;
                while(end1->next) end1=end1->next;
                end1->next=temp1;
                temp1->prev=end1;
                temp1->next=0;
                }
	

	temp->count--; //decrementing book count


	print("Book issued successfully..",68);
	newline(2);
	return;


}




