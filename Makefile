GCC = gcc -Wall -Werror
OBJ = build/mySimpleComputer.o build/myTerm.o build/myBigChars.o build/myReadkey.o build/curs.o build/printComp.o build/translator.o
HEAD = src/mySimpleComputer.h src/myTerm.h src/myBigChars.h src/myReadkey.h src/curs.h src/printComp.h src/translator.h

.PHONY: clean 

all: bin build test default

default: bin/SimpleComputer

test:bin/test

bin/SimpleComputer: build/Main.o $(OBJ)
	$(GCC) -std=c99 build/Main.o $(OBJ) -o bin/SimpleComputer

build/mySimpleComputer.o: src/mySimpleComputer.c src/mySimpleComputer.h
	$(GCC) -std=c99 -c src/mySimpleComputer.c -o build/mySimpleComputer.o

build/myTerm.o: src/myTerm.c src/myTerm.h
	$(GCC) -std=c99 -c src/myTerm.c -o build/myTerm.o

build/myBigChars.o: src/myBigChars.c src/myBigChars.h
	$(GCC) -std=c99 -c src/myBigChars.c -o build/myBigChars.o

build/myReadkey.o: src/myReadkey.c src/myReadkey.h
	$(GCC) -std=c99 -c src/myReadkey.c -o build/myReadkey.o

build/curs.o: src/curs.c src/curs.h
	$(GCC) -std=c99 -c src/curs.c -o build/curs.o

build/printComp.o: src/printComp.c src/printComp.h
	$(GCC) -std=c99 -c src/printComp.c -o build/printComp.o

build/translator.o: src/translator.c src/translator.h
	$(GCC) -std=c99 -c src/translator.c -o build/translator.o

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
