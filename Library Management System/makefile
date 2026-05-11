CC= gcc

lms: main.o menu.o read.o add.o save.o show.o update.o remove.o search.o issue.o issuedisplay.o return.o
	$(CC) main.o menu.o read.o add.o save.o show.o update.o remove.o search.o issue.o issuedisplay.o return.o -o lms

main.o: main.c func.h
	$(CC) -c main.c

menu.o: menu.c func.h
	$(CC) -c menu.c

read.o: read.c func.h
	$(CC) -c read.c

add.o: add.c func.h
	$(CC) -c add.c

save.o: save.c func.h
	$(CC) -c save.c

show.o: show.c func.h
	$(CC) -c show.c

update.o: update.c func.h
	$(CC) -c update.c

remove.o: remove.c func.h
	$(CC) -c remove.c

search.o: search.c func.h
	$(CC) -c search.c

issue.o: issue.c func.h
	$(CC) -c issue.c

issuedisplay.o: issuedisplay.c func.h
	$(CC) -c issuedisplay.c

return.o: return.c func.h
	$(CC) -c return.c

clear:
	rm -f *.o lms
