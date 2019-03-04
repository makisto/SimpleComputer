GCC = gcc -Wall -Werror
OBJ = build/mySimpleComputer.o build/myTerm.o
HEAD = src/mySimpleComputer.h src/myTerm.h

.PHONY: clean 

all: bin build test default

default: bin/SimpleComputer.exe

test:bin/test.exe

bin/SimpleComputer.exe: build/Main.o $(OBJ)
	$(GCC) build/Main.o $(OBJ) -o bin/SimpleComputer.exe

build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
	$(GCC) -c src/mySimpleComputer.c -o build/mySimpleComputer.o

build/myTerm.o: src/myTerm.c src/myTerm.h
	$(GCC) -c src/myTerm.c -o build/myTerm.o

build/Main.o: src/Main.c $(HEAD)
	$(GCC) -c src/Main.c -o build/Main.o 

bin/test.exe:build/test.o $(OBJ)
	$(GCC) $(FLAGS) build/test.o $(OBJ) -o bin/test.exe

build/test.o:test/test.c 
	$(GCC) -c -I thirdparty -I src -c test/test.c -o build/test.o

bin:
	mkdir bin

build:
	mkdir build

clean: 
	rm -rf bin build
