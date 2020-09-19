all: build run 

build: 
	gcc main.c -o main -std=c89

run: build
	./main.exe

clean:
	del main.exe

valgrind: build
	valgrind --leak-check=full ./main
	rm -rf ./main