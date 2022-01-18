CC = gcc
CFLAGS =-g -Wall

all: hello

hello: helloworld.o
	${CC} ${CFLAGS} -o $@ $^

%.o: %.c
	${CC} ${CFLAGS} -c $<

clean:
	rm helloworld.o hello

