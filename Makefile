GCC = gcc -Wall -Werror -std=c99
OBJ = build/mySimpleComputer.o build/myTerm.o build/printComp.o
HEAD = src/mySimpleComputer.h src/myTerm.h src/printComp.h

.PHONY: clean 

all: bin build test default

default: bin/SimpleComputer

test:bin/test

bin/SimpleComputer: build/Main.o $(OBJ)
	$(GCC) build/Main.o $(OBJ) -o bin/SimpleComputer

build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
	$(GCC) -c src/mySimpleComputer.c -o build/mySimpleComputer.o

build/myTerm.o: src/myTerm.c src/myTerm.h
	$(GCC) -c src/myTerm.c -o build/myTerm.o

build/printComp.o: src/printComp.c src/printComp.h
	$(GCC) -c src/printComp.c -o build/printComp.o

build/Main.o: src/Main.c $(HEAD)
	$(GCC) -c src/Main.c -o build/Main.o 

bin/test:build/test.o $(OBJ)
	$(GCC) $(FLAGS) build/test.o $(OBJ) -o bin/test

build/test.o:test/test.c 
	$(GCC) -c -I thirdparty -I src -c test/test.c -o build/test.o

bin:
	mkdir bin

build:
	mkdir build

clean: 
	rm -rf bin build
