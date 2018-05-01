CC=g++
CFLAGS=-std=c++11 -Wall
OUTPUTNAME=MergeSort

all: MergeSort
	$(CC) $(CFLAGS) *.o -o $(OUTPUTNAME)

MergeSort: MergeSort.cpp
	$(CC) $(CFLAGS) -c MergeSort.cpp

clean:
	rm *.o
	rm $(OUTPUTNAME)
