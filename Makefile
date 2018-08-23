CPPFLAGS = -g -O0 -std=c++11  #Debug symbols, and no optimization. c++11 standard.

#-------------------------------------------------------------
# Makefile Targets
#-------------------------------------------------------------

HEADERS = GameState.h PlayerState.h
OBJECTS = main.o GameState.o PlayerState.o

all: hangman

%.o: %.c $(HEADERS)
	g++ -c $(CPPFLAGS) $< -o $@

hangman: $(OBJECTS)
	g++ $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f hangman

