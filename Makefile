CC=g++
OPT=-Wall -std=c++11
COMPILE=$(OPT) -c
LINK=$(OPT) -o
APP=gportugol

SRCLEX=src/lexanalyzer/lexanalyzer.cpp  src/lexanalyzer/states.cpp $(SRCTXT)
SRCTXT=src/lexanalyzer/text/processor.cpp
SRCSYM=src/symbols/symbols_table.cpp src/symbols/token.cpp
SRC=src/main.cpp $(SRCLEX) $(SRCSYM)


all:
	$(CC) $(SRC) $(LINK) $(APP)

run:
	./$(APP)

rebuild: clean all

clean:
	rm -rf *.o $(APP)
