GCC = gcc -Wall -Werror
OBJ = build/mySimpleComputer.o build/myTerm.o build/myBigChars.o build/myReadkey.o build/printComp.o
HEAD = src/mySimpleComputer.h src/myTerm.h src/myBigChars.h src/myReadkey.h src/printComp.h

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

build/myBigChars.o: src/myBigChars.c src/myBigChars.h
	$(GCC) -c src/myBigChars.c -o build/myBigChars.o

build/myReadkey.o: src/myReadkey.c src/myReadkey.h
	$(GCC) -c src/myReadkey.c -o build/myReadkey.o

build/printComp.o: src/printComp.c src/printComp.h
	$(GCC) -c src/printComp.c -o build/printComp.o

build/Main.o: src/Main.c $(HEAD)
	$(GCC) -c src/Main.c -o build/Main.o 

bin/test:build/test.o $(OBJ)
	$(GCC) -std=c99 $(FLAGS) build/test.o $(OBJ) -o bin/test

build/test.o:test/test.c 
	$(GCC) -std=c99 -c -I thirdparty -I src -c test/test.c -o build/test.o

bin:
	mkdir bin

build:
	mkdir build

clean: 
	rm -rf bin build
