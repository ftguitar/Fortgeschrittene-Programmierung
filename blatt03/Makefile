# makefile for warmup

.PHONY: compile checkstyle format clean

../unity/unity.o: ../unity/unity.c ../unity/unity.h
	gcc -c ../unity/unity.c -o ../unity/unity.o

warmup.o: warmup.c
	gcc -c warmup.c

warmup: warmup.o ../unity/unity.o
	gcc -o warmup warmup.o ../unity/unity.o

symcrypt_lib.o: symcrypt_lib.c symcrypt_lib.h
	gcc -c symcrypt_lib.c

symcrypt_test.o: symcrypt_lib.h symcrypt_test.c
	gcc -c symcrypt_test.c

symcrypt_test: symcrypt_test.o ../unity/unity.o symcrypt_lib.o
	gcc -o symcrypt_test symcrypt_test.o ../unity/unity.o symcrypt_lib.o

symcrypt.o: symcrypt.c symcrypt_lib.h
	gcc -c symcrypt.c

symcrypt: symcrypt.o symcrypt_lib.o
	gcc -o symcrypt symcrypt.o symcrypt_lib.o


test: warmup symcrypt_test
	./warmup 
	./symcrypt_test

clean:
	rm -f *.o test warmup

format:
	clang-format -i *.c

checkstyle:
	clang-tidy --quiet *.c --

compile: warmup symcrypt symcrypt_test

