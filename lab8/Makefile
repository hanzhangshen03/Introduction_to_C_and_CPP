DEBUG_FLAGS=-fsanitize=address -fsanitize=undefined -g -fno-omit-frame-pointer -Wall -pedantic

all:
	gcc -Wall -pedantic -c matrix.c
	gcc -Wall -pedantic -c lab8.c
	gcc -o lab8 lab8.o matrix.o 

clang:
	clang -Wall -pedantic -c matrix.c
	clang -Wall -pedantic -c lab8.c
	clang -o lab8 lab8.o matrix.o 

clang-sane:
	clang ${DEBUG_FLAGS} -c matrix.c
	clang ${DEBUG_FLAGS} -c lab8.c
	clang ${DEBUG_FLAGS} -o lab8 lab8.o matrix.o 

sane:
	gcc ${DEBUG_FLAGS} -c matrix.c
	gcc ${DEBUG_FLAGS} -c lab8.c
	gcc ${DEBUG_FLAGS} -o lab8 lab8.o matrix.o 


clean:
	rm -f matrix.o lab8.o lab8
