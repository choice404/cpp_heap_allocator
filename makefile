# Makefile for Austin Choi's braifuck compiler

MAIN		= ./main.cpp
INCLUDES	= ./source/heap.cpp
OUTFILE		= ./heap

all: $(OUTFILE)

$(OUTFILE): main.cpp
	g++ -std=c++11 $(MAIN) $(INCLUDES) -o $(OUTFILE)

clean:
	rm -rf $(OUTFILE)
