CC=gcc
CFLAGS=-I. -DCONFIG_TEXTUI -DCONFIG_PLAYER_MANAGER_SCANF
DEPS = board.h game.h player_manager.h board_view.h
SRCS = main.c board.c game.c player_manager_scanf.c board_view_text.c
OBJS = main.o board.o game.o player_manager_scanf.o board_view_text.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $(CFLAGS) $(OBJS)
	
clean:
	rm -f cible $(OBJS)
	
