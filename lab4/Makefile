


all: lab4.pdf
	gcc -Wall -c lab4.c
	gcc -Wall -c tree.c 
	gcc -o lab4 lab4.o tree.o

lab4.pdf:
	pdflatex lab4.tex

clean:
	rm -f lab4.o tree.o lab4
