CC := g++
CPPFLAGS := -Wall -Wextra -O0 -MD -g

all: m.out

m.out: main.o Matrix.o
	$(CC) -o m.out $^

main.o: main.cpp

Matrix.o: Matrix.cpp

.PHONY: format
format: main.cpp Matrix.cpp Matrix.hpp
	clang-format --style="{BasedOnStyle: llvm, IndentWidth: 4}" -i $^

.PHONY: clean
clean:
	rm -rf *.o *.out *.d

-include *.d