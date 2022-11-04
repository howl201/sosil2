main.out: main.o initmenu.o menu.o worker.o
	gcc -o main.out main.o initmenu.o menu.o worker.o -lncurses

main.o: initmenu.h menu.h worker.h main.c
	gcc -c main.c -lncurses

initmenu.o: initmenu.h initmenu.c
	gcc -c initmenu.c -lncurses

worker.o: worker.h pmenu.h worker.c
	gcc -c worker.c pmenu.c -lncurses

menu.o: menu.h worker.h menu.c
	gcc -c menu.c

clean:
	rm -f *.o
