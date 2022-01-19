CC = gcc
CFLAGS =-g -Wall

all: test

test: test_header_file.o header_file.o
	${CC} ${CFLAGS} $^ -o $@

test_header_file.o: test_header_file.c
	${CC} ${CFLAGS} -c $^

header_file.o: header_file.h header_file.c
	${CC} ${CFLAGS} -c $^

clean:
	rm *.o test

