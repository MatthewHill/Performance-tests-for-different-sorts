CC=g++
CFLAGS=-std=c++11 -Wall
OUTPUTNAME=InsertionSort

all: InsertionSort LinkedList
	$(CC) $(CFLAGS) *.o -o $(OUTPUTNAME)

InsertionSort: InsertionSort.cpp
	$(CC) $(CFLAGS) -c InsertionSort.cpp

LinkedList: LinkedList.cpp
	$(CC) $(CFLAGS) -c LinkedList.cpp

clean:
	rm *.o
	rm $(OUTPUTNAME)