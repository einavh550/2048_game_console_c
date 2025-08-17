CC = gcc
OBJS = game.o main.o

CFLAGS = -Wall -Werror
EXEC = roy_ries__einav_hillel

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $@
    
game.o: game.c game.h
main.o: main.c game.h

clean:
	rm -f $(OBJS) $(EXEC)

