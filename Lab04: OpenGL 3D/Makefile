OPT = -g -DDEBUG

LIB = -lGL -lGLU -lglut

all: zadanie1.out zadanie3.out zadanie4.out

zadanie1.out: zadanie1.o 
	gcc $(OPT) zadanie1.o -o zadanie1.out $(LIB)

zadanie1.o: zadanie1.cpp
	gcc -c $(OPT) zadanie1.cpp

zadanie3.out: zadanie3.o 
	gcc $(OPT) zadanie3.o -o zadanie3.out $(LIB)

zadanie3.o: zadanie3.cpp
	gcc -c $(OPT) zadanie3.cpp

zadanie4.out: zadanie4.o 
	gcc $(OPT) zadanie4.o -o zadanie4.out $(LIB)

zadanie4.o: zadanie4.cpp
	gcc -c $(OPT) zadanie4.cpp

clean:
	rm -f *.o