CC = gcc
CFLAGS =-g -Wall

all: first

first: binary_search_tree.o first_tree_program.o
	${CC} ${CFLAGS} $^ -o $@

first_tree_program.o: first_tree_program.c
	${CC} ${CFLAGS} -c $^

binary_search_tree.o: binary_search_tree.h binary_search_tree.c
	${CC} ${CFLAGS} -c $^

clean:
	rm *.o first binary_search_tree.h.gch

