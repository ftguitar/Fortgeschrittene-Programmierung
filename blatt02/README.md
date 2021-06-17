# blatt02 (12.5 / 16.0)

Dein fib_fast funktioniert nicht für n > 4999, da die array dafür zu klein
ist (-1) (die if aus deiner main funktion sollte in deiner fib_fast funktion
sein)

Kein Headerguard bei der .h Datei (-0.5)

deine tests sollten alle in verschiedenen funktionen sein (-0.5)

fib_test sollte nicht in .PHONY stehen (-0.5)
nur das ausführen von fib_test soll bei test: stattfinden, nicht das
compilieren (-0.5)
du hast keine Regel für compile (-0.5)

Kann ich auf jeden Fall weiterleiten :)

## Build Log  🟢 (success)
### clone  🟢 (success)
```bash
Initialized empty Git repository in /drone/src/.git/
+ git fetch origin +refs/heads/master:
From https://git.inpro.informatik.uni-freiburg.de/2021-ss-c-kurs/tf166
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
+ git checkout 6c1007cc3fe9bb9a2f8d56d0927aae753f39f7ff -b master
Already on 'master'

```

### retrieve current sheet  🟢 (success)
```bash
+ export SHEET=$(curl https://courses.inpro.informatik.uni-freiburg.de/2021-SS/c-kurs/active_exercises | head -n 1)
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0100     7  100     7    0     0    120      0 --:--:-- --:--:-- --:--:--   120
+ echo Currently active exercise directory: $SHEET
Currently active exercise directory: blatt02
+ echo $SHEET > current_sheet

```

### make compile  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mmake: Nothing to be done for 'compile'.

```

### make test  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make test
[0mgcc -c fib_test.c
gcc -c fib_lib.c
gcc -c ../unity/unity.c -o ../unity/unity.o
gcc -o fib_test fib_test.o fib_lib.o ../unity/unity.o
./fib_test
fib_test.c:24:test_fib_slow:[42mPASS[00m
fib_test.c:25:test_fib_fast:[42mPASS[00m

-----------------------
2 Tests 0 Failures 0 Ignored 
[42mOK[00m

```

### make checkstyle  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make checkstyle
[0mclang-tidy --quiet *.c --
232 warnings generated.
232 warnings generated.
464 warnings generated.
778 warnings generated.
[1m/drone/src/blatt02/fib_fast.c:6:3: [0m[0;1;35mwarning: [0m[1mCall to function 'scanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'scanf_s' in case of C11 [clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling][0m
  scanf("%d", &n);
[0;1;32m  ^
[0m[1m/drone/src/blatt02/fib_fast.c:6:3: [0m[0;1;30mnote: [0mCall to function 'scanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'scanf_s' in case of C11[0m
[1m/drone/src/blatt02/fib_slow.c:6:3: [0m[0;1;35mwarning: [0m[1mCall to function 'scanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'scanf_s' in case of C11 [clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling][0m
  scanf("%d", &n);
[0;1;32m  ^
[0m[1m/drone/src/blatt02/fib_slow.c:6:3: [0m[0;1;30mnote: [0mCall to function 'scanf' is insecure as it does not provide security checks introduced in the C11 standard. Replace with analogous functions that support length arguments or provides boundary checks such as 'scanf_s' in case of C11[0m

```

### check clang-format  🟢 (success)
```bash
+ check_clang_format -r $(cat current_sheet)

```

### check erfahrungen.txt  🟢 (success)
```bash
+ check_erfahrungen $(cat current_sheet)

```
