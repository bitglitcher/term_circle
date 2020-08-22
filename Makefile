all:
	gcc main.c -g -lcurses -lm -o term_circle

clean:
	rm term_circle
