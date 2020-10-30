OPT = -g -DDEBUG

LIB = -lGL -lGLU -lglut -lm

all: zadanie1.out

zadanie1.out: zadanie1.o 
	gcc $(OPT) zadanie1.o -o zadanie1.out $(LIB)

zadanie1.o: zadanie1.cpp
	gcc -c $(OPT) zadanie1.cpp

clean:
	rm -f *.o