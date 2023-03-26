CC = gcc
CCFLAGS = -Wall -Wextra -std=c11 -pthread -o2 

all: serial parallel

serial: monte_carlo_serial.c
	$(CC) $(CCFLAGS) $^ -o monte_carlo_serial -lm

parallel: monte_carlo_parallel.c
	$(CC) $(CCFLAGS) $^ -o monte_carlo_parallel -lm

clean:
	$(RM) serial parallel
