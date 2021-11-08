CC = g++
CFLAGS = -O3 -Wall -Wno-unused-result

SOURCE_PATH = onegin.cpp 
TEST_PATH = unit_test.cpp
MAIN_PATH = main.cpp

OBJECTS = onegin.o unit_test.o main.o 
EXECUTABLE = Onegin

.PHONY: all install uninstall clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) 

main.o: $(MAIN_PATH)
	$(CC) $(CFLAGS) -c $(MAIN_PATH) -o main.o

onegin.o: $(SOURCE_PATH)
	$(CC) $(CFLAGS) -c $(SOURCE_PATH) -o onegin.o 

unit_test.o: $(TEST_PATH)
	$(CC) $(CFLAGS) -c $(TEST_PATH) -o unit_test.o

install:
	install $(EXECUTABLE)
uninstall:
	rm -rf $(EXECUTABLE)
clean:
	rm -rf *.o $(EXECUTABLE)
	