# This is an example makefile
# It is very important to add -lncursesw for the ncurses library
CC=g++
DEBUG=-g
CFLAGS=-c $(DEBUG)
FLAGS= $(DEBUG) -std=c++11
LDFLAGS=-lncursesw $(DEBUG)
SOURCES=Hand.cpp Card.cpp ./unittests/test.cpp ./utility/util.cpp
SOURCESTEST=./unittests/test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
OBJECTSTEST=$(SOURCESTEST:.cpptest=.o)
EXECUTABLE=display
EXECUTABLETEST=test

all: clean $(SOURCES) $(EXECUTABLE)
test: clean $(SOURCESTEST) $(EXECUTABLETEST)


$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(EXECUTABLETEST): $(OBJECTSTEST) 
	$(CC) $(OBJECTSTEST) $(LDFLAGS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

.cpptest.o:
	$(CC) $(FLAGS) $< -o $@


clean:
	rm -rf *.o $(EXECUTABLE) $(EXECUTABLETEST)

