#complete the dependency and action lines for the following targets

all: slowsnake

slowsnake: move.o place.o display.o driver.o
	cc move.o place.o display.o driver.o -o slowsnake -lncurses


# source file dependencies
#  You should fill these in and add any additional targets you need

place.o: place.h

move.o: move.h

driver.o: move.h place.h display.h

# utility targets

clean:
	rm -f *.o

real_clean: clean
