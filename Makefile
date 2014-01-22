all: main

%: %.c
	gcc -c $<
	gcc -c h1st0gram.c
	gcc main.o h1st0gram.o -o h1st0gram
	rm main.o h1st0gram.o
