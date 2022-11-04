menu.out: menu.o initmenu.o mainmenu.o worker.o
	gcc -o menu.out menu.o initmenu.o mainmenu.o worker.o -lncurses

menu.o: initmenu.h mainmenu.h worker.h menu.c
	gcc -c menu.c -lncurses

initmenu.o: initmenu.h initmenu.c
	gcc -c initmenu.c -lncurses

worker.o: worker.h comenu.h worker.c
	gcc -c worker.c comenu.c -lncurses

mainmenu.o: mainmenu.c mainmenu.h worker.h
	gcc -c mainmenu.c

clean:
	rm -f *.o
