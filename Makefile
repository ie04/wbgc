output: wbgc.o sanity.o error.o
	gcc error.o wbgc.o sanity.o -o wbgc

wbgc.o: wbgc.c
	gcc -c wbgc.c

sanity.o:
	gcc -c sanity.c

error.o:
	gcc -c error.c

clean:
	rm *.o
