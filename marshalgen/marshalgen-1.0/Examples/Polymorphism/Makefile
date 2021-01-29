#CC=/net/arch-solaris/gnu/packages/gcc-2.95.3/bin/g++
#CC=/net/arch-solaris/gnu/packages/gcc-3.0.1/bin/g++
CC=g++
CFLAGS=-g

.SUFFIXES: .cpp.o

.cpp.o :

check : run
	./a.out

run : test.o 
	$(CC) $(CFLAGS) test.o

test.o : test.cpp Animal.h MarshaledAnimal.h Cat.h MarshaledCat.h MarshaledMyString.h MarshaledObj.h
	$(CC) $(CFLAGS) -c -I. test.cpp

MarshaledAnimal.h : Animal.h
	../../marshalgen  Animal.h

MarshaledCat.h : Cat.h
	../../marshalgen  Cat.h

MarshaledMyString.h : MyString.h
	../../marshalgen  MyString.h

clean:
	rm -f a.out *.o *.msh MarshaledAnimal.h MarshaledCat.h MarshaledMyString.h
