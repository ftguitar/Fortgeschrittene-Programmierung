.PHONY: compile checkstyle format clean

../unity/unity.o: ../unity/unity.c ../unity/unity.h
	gcc -c ../unity/unity.c -o ../unity/unity.o

warmup_structs.o: warmup_structs.c
	gcc -c warmup_structs.c

warmup_structs: warmup_structs.o ../unity/unity.o
	gcc -o warmup_structs warmup_structs.o ../unity/unity.o

warmup_malloc.o: warmup_malloc.c
	gcc -c warmup_malloc.c

warmup_malloc: warmup_malloc.o ../unity/unity.o
	gcc -o warmup_malloc warmup_malloc.o ../unity/unity.o

test: warmup_structs warmup_malloc
	./warmup_structs
	./warmup_malloc

clean:
	rm -f *.o warmup_malloc warmup_structs

format: 
	clang-format -i *.c

checkstyle:
	clang-tidy --quiet *.c --

compile: warmup_structs warmup_malloc
