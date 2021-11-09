CC = gcc
CFLAGS = -O3

SOURCE_PATH = SolveSquare.c 
TEST_PATH = UnitTest.c
MAIN_PATH = main.c

OBJECTS = SolveSquare.o UnitTest.o main.o 
EXECUTABLE = SolveSquare

.PHONY: all install uninstall clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) -lm

main.o: $(MAIN_PATH)
	$(CC) $(CFLAGS) -c $(MAIN_PATH) -o main.o

SolveSquare.o: $(SOURCE_PATH)
	$(CC) $(CFLAGS) -c $(SOURCE_PATH) -o SolveSquare.o 

UnitTest.o: $(TEST_PATH)
	$(CC) $(CFLAGS) -c $(TEST_PATH) -o UnitTest.o

install:
	install $(EXECUTABLE)
uninstall:
	rm -rf $(EXECUTABLE)
clean:
	rm -rf *.o $(EXECUTABLE)
	