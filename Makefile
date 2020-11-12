CC=gcc
CFLAGS=-std=gnu99 -Wall -pedantic -g -lm
SOURCES= slave.c aplicacion.c vista.c

all: RUNME
	gcc myServer.c quineValidator.c gaussian.c RUN_ME.o -o myServer $(CFLAGS)
	gcc decoder.c -o decoder $(CFLAGS)
	
RUNME: RUN_ME.asm
	nasm -felf64 RUN_ME.asm -o RUN_ME.o


clean:
	rm -f *.o myServer RUN_ME.o decoder

.PHONY: all clean