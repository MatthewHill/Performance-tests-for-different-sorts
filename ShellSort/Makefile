CC=g++
CFLAGS=-std=c++11 -Wall
OUTPUTNAME=ShellSort

all: ShellSort
	$(CC) $(CFLAGS) *.o -o $(OUTPUTNAME)

ShellSort: ShellSort.cpp
	$(CC) $(CFLAGS) -c ShellSort.cpp
	
clean:
	rm *.o
	rm $(OUTPUTNAME)