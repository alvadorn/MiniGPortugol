CC=g++
OPT=-Wall -std=c++11
COMPILE=$(OPT) -c
LINK=$(OPT) -o
APP=gportugol

SRCLEX=lexanalyzer/lexanalyzer.cpp
SRCTXT=text/processor.cpp
SRC=main.cpp $(SRCLEX) $(SRCTXT)


all:
	$(CC) $(SRC) $(LINK) $(APP)



run:
	./$(APP)

clean:
	rm -rf *.o $(APP)

