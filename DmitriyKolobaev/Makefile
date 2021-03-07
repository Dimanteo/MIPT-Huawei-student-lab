CC := g++
CFLAGS = -Wall -Wextra -O0 -MD

all: main.o Matrix.o
	$(CC) -o matrix.out $^

.PHONY: clean
clean:
	rm *.o *.out *.d

-include *.d