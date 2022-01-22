CC = gcc
CFLAGS =-g -Wall

all: first

first: binary_search_tree.o basic_functions_bst.o
	${CC} ${CFLAGS} $^ -o $@

basic_functions_bst.o: basic_functions_bst.c
	${CC} ${CFLAGS} -c $^

binary_search_tree.o: binary_search_tree.h binary_search_tree.c
	${CC} ${CFLAGS} -c $^

clean:
	rm *.o first 

