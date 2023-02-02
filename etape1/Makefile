CC=gcc
CFLAGS=-I. -DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK
DEPS = board.h player.h player_manager.h game.h
SRCS = main.c board.c player.c player_manager.c game.c
OBJS = main.o board.o player.o player_manager.o game.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
	
clean:
	rm -f cible $(OBJS)
	
