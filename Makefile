GCC = gcc -Wall -Werror
OBJ = build/Main.o build/mySimpleComputer.o
HEAD = src/mySimpleComputer.h

.PHONY: clean 

all: bin build default

default: bin/SimpleComputer.exe

bin/SimpleComputer.exe: $(OBJ)
	$(GCC) $(OBJ) -o bin/SimpleComputer.exe

build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
	$(GCC) -c src/mySimpleComputer.c -o build/mySimpleComputer.o

build/Main.o: src/Main.c $(HEAD)
	$(GCC) -c src/Main.c -o build/Main.o 

bin:
	mkdir bin

build:
	mkdir build

clean: 
	rm -rf bin build
