# makefile for fib_library
.PHONY: compile fib_test checkstyle format clean

../unity/unity.o: ../unity/unity.c ../unity/unity.h
	gcc -c ../unity/unity.c -o ../unity/unity.o

fib_lib.o: fib_lib.c fib_lib.h
	gcc -c fib_lib.c

fib_test.o: fib_test.c fib_lib.h
	gcc -c fib_test.c

test: fib_test.o fib_lib.o  ../unity/unity.o 
	gcc -o fib_test fib_test.o fib_lib.o ../unity/unity.o
	./fib_test

fib_slow.o: fib_slow.c fib_lib.h
	gcc -c fib_slow.c

fib_slow: fib_slow.o fib_lib.o
	gcc -o fib_slow fib_slow.o fib_lib.o

fib_fast.o: fib_fast.c fib_lib.h
	gcc -c fib_fast.c

fib_fast: fib_fast.o fib_lib.o
	gcc -o fib_fast fib_fast.o fib_lib.o

clean:
	rm -f *.o fib_test fib_slow fib_fast

format:
	clang-format -i *.c

checkstyle:
	clang-tidy --quiet *.c --
