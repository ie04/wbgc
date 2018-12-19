# Variables
cc=gcc
CFLAGS=-c -Wall -Wextra -pedantic
SOURCES=wbgc.c error.c file.c vector.c
EXECUTABLE=wbgc
OBJECTS=wbgc.o sanity.o error.o file.o vector.o

all: $(EXECUTABLE)

debug: CFLAGS += -g
debug: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(cc) -o $(EXECUTABLE) $(OBJECTS)

wbgc.o: wbgc.c
sanity.o: sanity.c sanity.h
error.o: error.c error.h
file.o: file.c file.h
vector.o: vector.c vector.h

.PHONY: clean
clean:
	rm $(EXECUTABLE) $(OBJECTS)

