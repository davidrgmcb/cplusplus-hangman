CPPFLAGS = -g -O0  #Debug symbols, and no optimization

#-------------------------------------------------------------
# Makefile Targets
#-------------------------------------------------------------

HEADERS = classes.h
OBJECTS = classes.o

all: hangman

%.o: %.c $(HEADERS)
	g++ -c $(CFLAGS) $< -o $@

hangman: $(OBJECTS)
	g++ $(OBJECTS) -o $@

clean:
	-rm -f $(OBJECTS)
	-rm -f hangman

