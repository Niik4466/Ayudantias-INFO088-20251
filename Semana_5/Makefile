.PHONY = all clean
CC=g++
CFLAGS=-std=c++23 -Ofast -Wall -Wextra -Wconversion -Wdouble-promotion -Wduplicated-cond -Wfatal-errors -Wfloat-equal -Wformat=2 -Wlogical-op -Wpedantic -Wshadow -Wundef -Wno-unused-parameter -Wno-unused-result
BINS=bin/prog

all: clean $(BINS)

bin/%: Ejercicio1-y-2.cpp
	$(CC) $(CFLAGS) -o $@ $<

clean:
	@echo " [CLN] Removing binary files"
	@rm -f $(BINS)