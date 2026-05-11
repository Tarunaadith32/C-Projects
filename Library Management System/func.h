#ifndef func_h
#define func_h

// HEADER INCLUSIONS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

//ANSI ESCAPE SEQUENCES FOR TEXT CLR

#define YEL  "\033[33m" 
#define G "\033[32m" 
#define BOLD "\033[1m"  
#define RST  "\033[0m"


//STRUCTURE DEFINITIONS

typedef struct bookdata{
	unsigned int bookid;
	char title[50];
	char author[50];
	unsigned int count;

	struct bookdata *prev;
	struct bookdata *next;
}book;

typedef struct issuedata{
	unsigned int issueid;
	unsigned int bookid;
	unsigned int userid;
	char name[50];
	char issuedate[50];
	char duedate[50];
	char returndate[50];
	long duecode;
	int fine;
 
 	struct issuedata *prev;
        struct issuedata *next;
}issue;

//POINTERS AND VARIABLE DECLARATIONS 
extern book* bookptr;
extern issue* issueptr;
extern unsigned int bookid;
extern unsigned int issueid;

// FUNCTION DECLARATIONS

void read(void);

void add(void);

void save(void);

void show(void);

void update(void);

void book_remove(void);

void book_search(void);

void book_issue(void);

void issue_display(void);

void book_return(void);

void print_menu(void);     //Functions to print
void print(char*,int);
void newline(int);
void space(int n);
void clrprint(char*,char*,int);

void bookprint(book*); //(Present in update.c file)


#endif
