all: add.c ass4.c mult.c sub.c arbprecision.h divi.c
	gcc -fPIC -c add.c
	gcc -fPIC -c extra.c
	gcc -fPIC -c divi.c
	gcc -fPIC -c sub.c
	gcc -fPIC -c mult.c
	gcc -shared -o arbprecision.so add.o sub.o mult.o extra.o divi.o
	gcc -c ass4.c -lm
	gcc -o mainfile ass4.o arbprecision.so -lm
	
clean:
	rm -rf *.o
	rm -f mainfile
