OPT = -g -DDEBUG

LIB = -lGL -lGLU -lglut

all: przyklad1.out przyklad2.out przyklad3.out zadanie1.out zadanie2.out

przyklad1.out: przyklad1.o 
	gcc $(OPT) przyklad1.o -o przyklad1.out $(LIB)

przyklad1.o: przyklad1.cpp
	gcc -c $(OPT) przyklad1.cpp

przyklad2.out: przyklad2.o 
	gcc $(OPT) przyklad2.o -o przyklad2.out $(LIB)

przyklad2.o: przyklad2.cpp
	gcc -c $(OPT) przyklad2.cpp

przyklad3.out: przyklad3.o 
	gcc $(OPT) przyklad3.o -o przyklad3.out $(LIB)

przyklad3.o: przyklad3.cpp
	gcc -c $(OPT) przyklad3.cpp

zadanie1.out: zadanie1.o 
	gcc $(OPT) zadanie1.o -o zadanie1.out $(LIB)

zadanie1.o: zadanie1.cpp
	gcc -c $(OPT) zadanie1.cpp

zadanie2.out: zadanie2.o 
	gcc $(OPT) zadanie2.o -o zadanie2.out $(LIB)

zadanie2.o: zadanie2.cpp
	gcc -c $(OPT) zadanie2.cpp

clean:
	rm -f *.o