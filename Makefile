compile: build/main.o build/sorts.o
	gcc -O3 build/main.o build/sorts.o -o bin/main.out

text: src/makeTextFile.c
	gcc -O3 src/makeTextFile.c -o bin/makeTextFile.out
	./bin/makeTextFile.out

build/main.o: src/main.c
	gcc -O3 -c src/main.c -o build/main.o

build/sorts.o: src/sorts.c
	gcc -O3 -c src/sorts.c -o build/sorts.o

clean:
	rm -f build/*
	rm -f bin/*
	rm -f input/*

run: bin/main.out
	./bin/main.out
