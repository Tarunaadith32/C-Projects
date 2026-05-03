student: main.o menu.o stud_add.o stud_show.o stud_save.o stud_exit.o stud_del.o delete_all.o stud_rev.o stud_mod.o stud_sort.o read.o
	gcc menu.o main.o stud_add.o stud_show.o stud_save.o stud_exit.o stud_del.o delete_all.o stud_rev.o read.o stud_mod.o stud_sort.o -o student 

main.o: main.c menu.h func.h
	gcc -c main.c

menu.o: menu.c menu.h 
	gcc -c menu.c

stud_add.o: stud_add.c func.h menu.h
	gcc -c stud_add.c

stud_show.o: stud_show.c func.h menu.h
	gcc -c stud_show.c

stud_save.o: stud_save.c func.h menu.h
	gcc -c stud_save.c

stud_exit.o: stud_exit.c func.h menu.h
	gcc -c stud_exit.c

read.o: read.c func.h menu.h
	gcc -c read.c

stud_del.o: stud_del.c func.h menu.h
	gcc -c stud_del.c

stud_rev.o: stud_rev.c func.h menu.h
	gcc -c stud_rev.c

stud_mod.o: stud_mod.c func.h menu.h
	gcc -c stud_mod.c

delete_all.o: delete_all.c func.h menu.h
	gcc -c delete_all.c

stud_sort.o: stud_sort.c func.h menu.h
	gcc -c stud_sort.c

clear:
	rm -f *.o student 

