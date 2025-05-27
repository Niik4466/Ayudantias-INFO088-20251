.PHONY = all clean
CC=g++
CFLAGS=-std=c++26 -O3 -ffast-math -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter -Wno-unused-result
BINS=prog
SRC ?= ejercicio1_resuelto.cpp

all: clean $(BINS)

prog: $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)
