#ifndef func_h
#define func_h

typedef struct student{
        int roll;
        char name[20];
        float percent;
        struct student* next;
}st;

extern st* hptr;
extern int rollno;

void stud_add(void);
void stud_show(void);
void stud_save(void);
void read_data(void);
void stud_exit(void);
void stud_del(void);
void stud_print(void);
void delete_all(void);
void stud_rev(void);
void stud_mod(void);
void stud_sort(void);

void print_onestudent(st*);

#endif
