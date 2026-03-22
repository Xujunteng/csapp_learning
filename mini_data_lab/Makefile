#
# Makefile that builds btest and other helper programs for the CS:APP data lab
# 
CC = gcc
CFLAGS = -O -Wall -m64 -std=gnu89
LIBS = -lm

all: btest

btest: btest.c bits.c decl.c tests.c btest.h bits.h
	$(CC) $(CFLAGS) $(LIBS) -o btest bits.c btest.c decl.c tests.c


clean:
	rm -f *.o btest *~


