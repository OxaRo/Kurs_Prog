CXX = g++
CFLAGS = -c -Wall -Werror 
.PHONY: all clean
OBJECTS = 22-vrsk.o

all: bin bin/prog

bin/prog: $(OBJECTS)
	$(CXX) $(OBJECTS) -o bin/prog

bin/22-vrsk.o: 22-vrsk.cpp
	$(CXX) $(CFLAGS) 22-vrsk.cpp -o 22-vrsk.o

bin:
	mkdir bin
clean:
	rm bin/*
