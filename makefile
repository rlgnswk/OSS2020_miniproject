a.out: main.o base.o extras.o
	gcc -o a.out  main.o base.o extras.o

base.o: base.c
	gcc -c -o base.o base.c

extras.o: extras.c
	gcc -c -o extras.o extras.c

main.o: main.c
	gcc -c -o main.o main.c

clean:
	rm a.out main.o base.o extras.o
