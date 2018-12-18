output: wbgc.o sanity.o error.o file.o
	gcc error.o wbgc.o sanity.o file.o -o wbgc

wbgc.o: wbgc.c
	gcc -c wbgc.c

sanity.o:
	gcc -c sanity.c

error.o:
	gcc -c error.c

file.o:
	gcc -c file.c

clean:
	rm *.o
