all: main

%: %.c
	gcc $< -o h1st0gram

