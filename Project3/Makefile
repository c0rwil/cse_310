EXEC = PJ3
CC = g++
CFLAGS = -c -Wall
#
$(EXEC): main.o min-heap.o
	$(CC) -o $(EXEC) main.o min-heap.o
#
main.o: main.cpp min-heap.h
	$(CC) $(CFLAGS) main.cpp
#
min-heap.o: min-heap.cpp min-heap.h
	$(CC) $(CFLAGS) min-heap.cpp
