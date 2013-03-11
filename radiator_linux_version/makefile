#!/bin/bash

CC = g++
files = main.cpp radiator.cpp installation.cpp cauldron.cpp
objects = main.o radiator.o installation.o cauldron.o
MAIN = kalorifer

CFLAGS = -Wall -Wextra

.PHONY: all
all: $(MAIN)
	@echo "Kalorifer System compiled!"

$(MAIN): $(objects)
	$(CC) $(CFLAGS) $(objects) -o $@

cauldron.o			:  cauldron.cpp globals.h cauldron.h
			  	$(CC) -c -g cauldron.cpp


radiator.o			: radiator.cpp globals.h radiator.h
			  	$(CC) -c -g radiator.cpp
			  
installation.o		: installation.cpp globals.h installation.h radiator.h cauldron.h
			  	$(CC) -c -g installation.cpp
			  
main.o				: main.cpp globals.h installation.h radiator.h cauldron.h
			  	$(CC) -c -g main.cpp

	rm -f *.o *~ *.out
			  
.PHONY: clean
clean:
	@echo "all object files will be deleted!"
	rm -f *.o *~ *.out
			  
				
