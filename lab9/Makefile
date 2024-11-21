FLAGS=-g -Wall -pedantic 

all: lab9.pdf
	gcc ${FLAGS} -Wall -pedantic -c lab9.c
	gcc ${FLAGS} -Wall -pedantic -c parse.c
	gcc ${FLAGS} -Wall -pedantic -c expr.c
	gcc ${FLAGS} -o lab9 lab9.o parse.o expr.o 

lab9.pdf:
	pdflatex -shell-escape lab9.tex

clean:
	rm -f lab9 lab9.o parse.o expr.o 
