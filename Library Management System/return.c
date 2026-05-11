#include "func.h"

void book_return(void){
	
	unsigned int bookid,userid;
        system("clear");
        newline(11);
        print("=====================================\n",0);
        space(67);
       printf("|| ********"YEL BOLD" RETURN A BOOK "RST"******** ||\n");
        print("=====================================\n",0);
        newline(2);
        print("Enter Book ID : ",68);
	scanf(" %u",&bookid);
	newline(1);
	print("Enter User ID : ",68);
	scanf(" %u",&userid);
	newline(1);
	issue* temp=issueptr;
	while((temp!=0)&&(temp->bookid!=bookid)&&(temp->userid!=userid)) temp=temp->next;
	if(temp==0){
		print("No issue found..",68);
		return;
	}
	long curr=time(NULL);

	book* temp1=bookptr;
	while(temp->bookid!=temp1->bookid) temp1=temp1->next;
	temp1->count++;
	
	system("clear");
	newline(11);

        print("=====================================================================================================================================\n",0);
	space(19);
        printf("||"G BOLD" ISSUE ID "RST"|"G BOLD" BOOK ID "RST"|"G BOLD" USER ID "RST"| "G BOLD"     USERNAME      "RST"|   "G BOLD"            TITLE   "RST"       | "G BOLD"ISSUEDATE"RST"  |  "G BOLD"DUEDATE"RST"   | "G BOLD"RETURNDATE"RST" | "G BOLD" FINE "RST"||\n");
        print("=====================================================================================================================================\n",0);
	space(19);
        printf("||    %-4u  |   %-4u  |  %-4u   | %-19s| %-29s| %-11s| %-11s| %-11s| %-3dRs ||",temp->issueid,temp->bookid,temp->userid,temp->name,temp1->title,temp->issuedate,temp->duedate,temp->returndate,temp->fine);
	newline(1);
        print("=====================================================================================================================================\n",0);
	newline(2);
	int days=(curr-(temp->duecode))/(3600*24);
	if(days>0){
		space(45);
		printf(BOLD"Fine amount : %d Rs" RST,days*2);
		newline(2);
	}
		print(" [1] -- Confirm Return     [2] -- Return to main menu : ",45);
		int op;
		scanf(" %d",&op);
		newline(2);
		if(op==1){
			struct tm* rettime;
			rettime=localtime(&curr);
			strftime(temp->returndate,sizeof(temp->returndate),"%d %b %Y",rettime);
			temp->fine=(days*2);
			print("Book returned successfuly..",45);
			newline(2);
			return;

		}
		else return;
	}

