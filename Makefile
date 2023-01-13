CC=gcc
CFLAGS=-I. -DSYMBOL1 -DSYMBOL2
DEPS = board.h test_CheckEndOfGame.h
SRCS = board.c main.c test_CheckEndOfGame.c
OBJS = board.o main.o test_CheckEndOfGame.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

cible: $(OBJS)
	$(CC) -o $@ $< $(CFLAGS)
	
clean:
	rm -f cible $(OBJS)
	
