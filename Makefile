output: wbgc.o
	gcc wbgc.o -o wbgc

wbgc.o: wbgc.c
	gcc -c wbgc.c

clean:
	rm *.o wbgc
