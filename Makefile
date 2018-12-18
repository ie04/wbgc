output: wbgc.o sanity.o error.o file.o vector.o
	gcc error.o wbgc.o sanity.o vector.o file.o -o wbgc

wbgc.o: wbgc.c
	gcc -c wbgc.c

sanity.o: sanity.c
	gcc -c sanity.c

error.o: error.c
	gcc -c error.c

file.o: file.c
	gcc -c file.c

vector.o:
	gcc -Wall -pedantic -Wstrict-prototypes -Werror -c vector.c

clean:
	rm *.o
