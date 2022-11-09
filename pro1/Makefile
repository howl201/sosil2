main.out: main.o initmenu.o menu.o worker.o pmenu.o driveracc.o initm.o addmember.o sgrade.o chmember.o
	gcc -o main.out main.o initmenu.o menu.o pmenu.o worker.o driveracc.o initm.o addmember.o sgrade.o chmember.o -lncurses

main.o: initmenu.h menu.h worker.h main.c
	gcc -c main.c -lncurses

initmenu.o: initmenu.h initmenu.c
	gcc -c initmenu.c -lncurses

pmenu.o: pmenu.h pmenu.c
	gcc -c pmenu.c -lncurses

worker.o: worker.h pmenu.h worker.c
	gcc -c worker.c -lncurses

menu.o: menu.h worker.h menu.c
	gcc -c menu.c -lncurses

driveracc.o: driveracc.h driveracc.c
	gcc -c driveracc.c -lncurses

initm.o: initm.h initm.c
	gcc -c initm.c -lncurses

addmember.o: addmember.h addmember.c
	gcc -c addmember.c -lncurses

sgrade.o: sgrade.h sgrade.c
	gcc -c sgrade.c -lncurses

chmember.o: chmember.h chmember.c
	gcc -c chmember.c -lncurses
clean:
	rm -f *.o
