CC=g++
OPT=-Wall -std=c++11
COMPILE=$(OPT) -c
LINK=$(OPT) -o
APP=gportugol

SRCLEX=src/lexanalyzer/lexanalyzer.cpp  src/lexanalyzer/states.cpp

SRC=src/main.cpp $(SRCLEX)


all:
	$(CC) $(SRC) $(LINK) $(APP)

run:
	./$(APP)

rebuild: clean all

clean:
	rm -rf *.o $(APP)
