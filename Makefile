CC=g++
CFLAGS=-g -O0 -Wall
DEPS=engine.h dll.h node.h iostream.h 
LDFLAGS=-lncurses -g
OBJ=main.o engine.o dll.o node.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hw1: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean

clean:
	rm $(OBJ) hw1 *.h.gch 
