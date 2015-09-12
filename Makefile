CC=g++
OPT=-Wall -std=c++11
COMPILE=$(OPT) -c
LINK=$(OPT) -o
APP=gportugol

SRCLEX=lexanalyzer/lexanalyzer.cpp lexanalyzer/keywords.cpp
SRCTXT=text/processor.cpp
SRCTKN=token/token.cpp

SRC=main.cpp $(SRCLEX) $(SRCTXT) $(SRCTKN)


all:
	$(CC) $(SRC) $(LINK) $(APP)

run:
	./$(APP)

rebuild: clean all

clean:
	rm -rf *.o $(APP)
