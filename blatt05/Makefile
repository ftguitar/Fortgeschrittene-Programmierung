.PHONY: compile checkstyle format clean

../unity/unity.o: ../unity/unity.c ../unity/unity.h
	gcc -fsanitize=address -g -c ../unity/unity.c -o ../unity/unity.o

vec.o: vec.c vec.h
	gcc -fsanitize=address -g -c vec.c

vec_test.o: vec_test.c vec.c
	gcc -fsanitize=address -g -c vec_test.c 

vec_test: vec_test.o ../unity/unity.o vec.o
	gcc -fsanitize=address -g vec_test.o -o vec_test ../unity/unity.o vec.o

statistics.o: statistics.c vec.h
	gcc -fsanitize=address -g -c statistics.c

statistics: statistics.o vec.o
	gcc -fsanitize=address -g statistics.o vec.o -o statistics

test: vec_test
	./vec_test

clean:
	rm -f *.o vec_test vec 

format:
	clang-format -i *.c

checkstyle:
	clang-tidy --quiet *.c --

compile: vec_test statistics 
