# blatt03 (14.5 / 16.0)


symcrypt_test sollte nicht in compile: sein (-0.5)

#include "string.h" sollte #include <string.h> sein
#include "stdio.h" sollte #include <stdio.h> sein

Kein headerguard in der .h datei (-1) bitte, kommentiere die datei auch!

## Build Log  🟢 (success)
### clone  🟢 (success)
```bash
Initialized empty Git repository in /drone/src/.git/
+ git fetch origin +refs/heads/master:
From https://git.inpro.informatik.uni-freiburg.de/2021-ss-c-kurs/tf166
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
+ git checkout 5819522336ba12406357eb519d15d207d83162c9 -b master
Already on 'master'

```

### retrieve current sheet  🟢 (success)
```bash
+ export SHEET=$(curl https://courses.inpro.informatik.uni-freiburg.de/2021-SS/c-kurs/active_exercises | head -n 1)
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0100     7  100     7    0     0    106      0 --:--:-- --:--:-- --:--:--   106
+ echo Currently active exercise directory: $SHEET
Currently active exercise directory: blatt03
+ echo $SHEET > current_sheet

```

### make compile  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mgcc -c warmup.c
gcc -c ../unity/unity.c -o ../unity/unity.o
gcc -o warmup warmup.o ../unity/unity.o
gcc -c symcrypt.c
gcc -c symcrypt_lib.c
gcc -o symcrypt symcrypt.o symcrypt_lib.o
gcc -c symcrypt_test.c
gcc -o symcrypt_test symcrypt_test.o ../unity/unity.o symcrypt_lib.o

```

### make test  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make test
[0m./warmup 
warmup.c:51:test_my_strlen_1:[42mPASS[00m
warmup.c:52:test_my_strlen_2:[42mPASS[00m
warmup.c:53:test_my_strcmp_1:[42mPASS[00m
warmup.c:54:test_my_strcmp_2:[42mPASS[00m
warmup.c:55:test_my_strcmp_3:[42mPASS[00m

-----------------------
5 Tests 0 Failures 0 Ignored 
[42mOK[00m
./symcrypt_test
symcrypt_test.c:68:test_encrypt_char_1:[42mPASS[00m
symcrypt_test.c:69:test_encrypt_char_2:[42mPASS[00m
symcrypt_test.c:70:test_encrypt_char_3:[42mPASS[00m
symcrypt_test.c:71:test_decrypt_char_1:[42mPASS[00m
symcrypt_test.c:72:test_decrypt_char_2:[42mPASS[00m
symcrypt_test.c:73:test_decrypt_char_3:[42mPASS[00m
symcrypt_test.c:74:test_encrypt_1:[42mPASS[00m
symcrypt_test.c:75:test_encrypt_2:[42mPASS[00m
symcrypt_test.c:76:test_decrypt_1:[42mPASS[00m
symcrypt_test.c:77:test_decrypt_2:[42mPASS[00m

-----------------------
10 Tests 0 Failures 0 Ignored 
[42mOK[00m

```

### make checkstyle  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make checkstyle
[0mclang-tidy --quiet *.c --
352 warnings generated.
704 warnings generated.
1138 warnings generated.
1452 warnings generated.

```

### check clang-format  🟢 (success)
```bash
+ check_clang_format -r $(cat current_sheet)

```

### check erfahrungen.txt  🟢 (success)
```bash
+ check_erfahrungen $(cat current_sheet)

```
