GCC=gcc
ASM=nasm
CFLAGS=-std=gnu99 -Wall -pedantic -g -lm
ASMFLAGS=-felf64
SERVER_SOURCES=$(wildcard dependencies/server/*.c)
SERVER_SOURCES_ASM=$(wildcard dependencies/server/*.asm)
DECODER_SOURCES=$(wildcard dependencies/decoder/*.c)
SERVER_OBJECTS=$(SERVER_SOURCES:.c=.o)
SERVER_OBJECTS_ASM=$(SERVER_SOURCES_ASM:.asm=.o)
DECODER_OBJECTS=$(DECODER_SOURCES:.c=.o)
DECODER_OBJECTS_ASM=$(DECODER_SOURCES_ASM:.asm=.o)

all:
	make server
	make decoder

decoder: $(DECODER_OBJECTS) $(DECODER_OBJECTS_ASM)
	$(GCC) -o decoder $(DECODER_OBJECTS) $(DECODER_OBJECTS_ASM) $(CFLAGS)

server: $(SERVER_OBJECTS) $(SERVER_OBJECTS_ASM)
	$(GCC) -o myServer $(SERVER_OBJECTS) $(SERVER_OBJECTS_ASM) $(CFLAGS)

%.o: %.c
	$(GCC) -c $< -o $@  $(CFLAGS)

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -f */*/*.o myServer decoder

.PHONY: all clean