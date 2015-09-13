CC=g++
OPT=-Wall -std=c++11
COMPILE=$(OPT) -c
LINK=$(OPT) -o
APP=gportugol

SRCLEX=src/lexanalyzer/lexanalyzer.cpp src/lexanalyzer/keywords.cpp
SRCTXT=src/text/processor.cpp
SRCTKN=src/token/token.cpp

SRC=src/main.cpp $(SRCLEX) $(SRCTXT) $(SRCTKN)


all:
	$(CC) $(SRC) $(LINK) $(APP)

run:
	./$(APP)

rebuild: clean all

clean:
	rm -rf *.o $(APP)
