CC=gcc
CFLAGS=-I. -DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_MOCK
DEPS = board.h game.h player_manager.h board_view.h
SRCS = main.c board.c game.c player_manager_mock.c board_view.c
OBJS = main.o board.o game.o player_manager_mock.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
	
clean:
	rm -f cible $(OBJS)
	
