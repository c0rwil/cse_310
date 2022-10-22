EXEC = PJ2
CC = g++
CFLAGS = -c -Wall
#
$(EXEC): main.o heap.o
	$(CC) -o $(EXEC) main.o heap.o
#
main.o: main.cpp heap.h util.h
	$(CC) $(CFLAGS) main.cpp
#
heap.o :heap.cpp heap.h
	$(CC) $(CFLAGS) heap.cpp