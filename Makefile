all:
	gcc main.c -g -lcurses -lm -o snake

clean:
	rm snake
