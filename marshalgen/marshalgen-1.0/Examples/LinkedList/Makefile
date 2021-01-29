CC=g++
CFLAGS=-g

.SUFFIXES: .cpp.o

.cpp.o :

check : run
	./a.out

run : LinkedList.o 
	$(CC) $(CFLAGS) LinkedList.o 

LinkedList.o : LinkedList.cpp LinkedList.h MarshaledLinkedList.h
	$(CC) $(CFLAGS) -c -I. LinkedList.cpp

MarshaledLinkedList.h : LinkedList.h ../../marshalgen
	../../marshalgen  LinkedList.h

clean:
	rm -f a.out *.o LinkedList.msh MarshaledList.h MarshaledLinkedList.h
