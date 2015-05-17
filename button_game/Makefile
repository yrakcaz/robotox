EXE=button_game
CC=gcc
SRCDIR=src
INCDIR=include/
CFLAGS=-g3 -Wall -Wextra -Werror -std=c99 -pedantic
LDFLAGS=-I$(INCDIR) -lwiringPi
SRC=$(SRCDIR)/game.c $(SRCDIR)/main.c
OBJ=$(SRC:.c=.o)


all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(CFLAGS) -o $(EXE) $^ $(LDFLAGS) 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OBJ)

distclean: clean
	rm -f $(EXE)

.PHONY: all clean distclean 
