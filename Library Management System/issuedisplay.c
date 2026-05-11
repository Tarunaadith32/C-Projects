#include "func.h"

void issue_display(void){
	system("clear");
	newline(11);
	print("=====================================================================================================================================\n",0);
	space(19);
	printf("||***************************************************** " YEL BOLD "LIST OF ISSUED BOOKS" RST " ******************************************************||\n");
	print("=====================================================================================================================================\n",0);
	
	if(issueptr==0){
	print("||                                                        NO ISSUE AVAILABLE                                                       ||\n",0);
	print("=====================================================================================================================================\n",0);
	newline(1);
	}
	
	else{
		space(19);
		printf("||"G BOLD" ISSUE ID "RST"|"G BOLD" BOOK ID "RST"|"G BOLD" USER ID "RST"| "G BOLD"     USERNAME      "RST"|   "G BOLD"            TITLE   "RST"       | "G BOLD"ISSUEDATE"RST"  |  "G BOLD"DUEDATE"RST"   | "G BOLD"RETURNDATE"RST" | "G BOLD" FINE "RST"||\n");
		print("=====================================================================================================================================\n",0);
		issue *temp=issueptr;
		book *temp1;
		while(temp){
		
			temp1=bookptr;
			while((temp1!=0)&&(temp1->bookid!=temp->bookid)) temp1=temp1->next;		
			space(19);
        		printf("||    %-4u  |   %-4u  |  %-4u   | %-19s| %-29s| %-11s| %-11s| %-11s| %-3dRs ||",temp->issueid,temp->bookid,temp->userid,temp->name,temp1->title,temp->issuedate,temp->duedate,temp->returndate,temp->fine);
			newline(1);
			temp=temp->next;
		}
		print("=====================================================================================================================================\n",0);
		newline(2);
	}
}
