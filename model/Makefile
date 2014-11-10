# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC=g++
DEBUG=-g
CFLAGS=-c $(DEBUG) -std=c++11
FLAGS =$(DEBUG) -std=c++11
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Hand.cpp Card.cpp ./unittests/test.cpp
SOURCESTEST=./unittests/test.cpp Hand.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OBJECTSTEST=$(SOURCESTEST:.cpptest=.o)
EXECUTABLE=display
EXECUTABLETEST=test

all: clean $(SOURCES) $(EXECUTABLE)
test: clean
	$(CC) -std=c++11 -g $(SOURCESTEST) -o test


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@


.cpp.o:
	$(CC) $(CFLAGS) $< -o $@



clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLETEST)

