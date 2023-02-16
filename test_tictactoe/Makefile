CC=gcc
CFLAGS=-I. -DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK
DEPS = board.h test_CheckEndOfGame.h 
SRCS = board.c test_CheckEndOfGame.c main.c
OBJS = board.o test_CheckEndOfGame.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
	
clean:
	rm -f cible $(OBJS)
	
