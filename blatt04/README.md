# blatt04 (10.5 / 16.0)



fib_fast sollte +1 in dem malloc haben (-0.5)
Das mit dem free() bei repeat funktioniert leider nicht so: da du den
string noch brauchst solltest du kein free() ausführen (-1)

wenn du bei join() break ausführst, verlässt du die ganze while-Schleife und
fügst den letzten string nicht hinzu. (-2)

bool if_find_beg1 = true; ist verwirrend benannt/gestellt, bitte pass darauf
auf, dass dein Code gut lesbar ist.

statt i++ in find_quoted() solltest du continue; benutzen und
free(s_new); führt zu dem gleichen problem wie früher (-2)

### make test  🔴 (failure)
```bash
+ cd $(cat current_sheet)
+ make test
[0m./warmup_structs
warmup_structs.c:106:test_add_3:[42mPASS[00m
warmup_structs.c:107:test_assign_add_3:[42mPASS[00m
warmup_structs.c:108:test_add_point:[42mPASS[00m
warmup_structs.c:109:test_add_assign_point:[42mPASS[00m
warmup_structs.c:110:test_find_char1:[42mPASS[00m
warmup_structs.c:111:test_find_char2:[42mPASS[00m

-----------------------
6 Tests 0 Failures 0 Ignored 
[42mOK[00m
./warmup_malloc
warmup_malloc.c:166:test_fib_fast_1:[42mPASS[00m
warmup_malloc.c:167:test_fib_fast_0:[42mPASS[00m
warmup_malloc.c:168:test_fib_fast_10:[42mPASS[00m
warmup_malloc.c:74:test_repeat:[41mFAIL[00m: Expression Evaluated To FALSE
foofoofoo,
u��`
warmup_malloc.c:117:test_join:[41mFAIL[00m: Expression Evaluated To FALSE
warmup_malloc.c:155:test_find_quoted:[41mFAIL[00m: Expression Evaluated To FALSE
bar
u��`
warmup_malloc.c:174:test_find_quoted2:[42mPASS[00m

-----------------------
7 Tests 3 Failures 0 Ignored 
[41mFAIL[00m
make: *** [Makefile:20: test] Error 3

```



## Build Log  🔴 (failure)
### clone  🟢 (success)
```bash
Initialized empty Git repository in /drone/src/.git/
+ git fetch origin +refs/heads/master:
From https://git.inpro.informatik.uni-freiburg.de/2021-ss-c-kurs/tf166
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
+ git checkout d40f4e3fadc42395df083d61ca9bc0af2a708f53 -b master
Already on 'master'

```

### retrieve current sheet  🟢 (success)
```bash
+ export SHEET=$(curl https://courses.inpro.informatik.uni-freiburg.de/2021-SS/c-kurs/active_exercises | head -n 1)
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0100     7  100     7    0     0    122      0 --:--:-- --:--:-- --:--:--   122
+ echo Currently active exercise directory: $SHEET
Currently active exercise directory: blatt04
+ echo $SHEET > current_sheet

```

### make compile  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mgcc -c warmup_structs.c
gcc -c ../unity/unity.c -o ../unity/unity.o
gcc -o warmup_structs warmup_structs.o ../unity/unity.o
gcc -c warmup_malloc.c
gcc -o warmup_malloc warmup_malloc.o ../unity/unity.o

```

### make test  🔴 (failure)
```bash
+ cd $(cat current_sheet)
+ make test
[0m./warmup_structs
warmup_structs.c:106:test_add_3:[42mPASS[00m
warmup_structs.c:107:test_assign_add_3:[42mPASS[00m
warmup_structs.c:108:test_add_point:[42mPASS[00m
warmup_structs.c:109:test_add_assign_point:[42mPASS[00m
warmup_structs.c:110:test_find_char1:[42mPASS[00m
warmup_structs.c:111:test_find_char2:[42mPASS[00m

-----------------------
6 Tests 0 Failures 0 Ignored 
[42mOK[00m
./warmup_malloc
warmup_malloc.c:166:test_fib_fast_1:[42mPASS[00m
warmup_malloc.c:167:test_fib_fast_0:[42mPASS[00m
warmup_malloc.c:168:test_fib_fast_10:[42mPASS[00m
warmup_malloc.c:74:test_repeat:[41mFAIL[00m: Expression Evaluated To FALSE
foofoofoo,
u��`
warmup_malloc.c:117:test_join:[41mFAIL[00m: Expression Evaluated To FALSE
warmup_malloc.c:155:test_find_quoted:[41mFAIL[00m: Expression Evaluated To FALSE
bar
u��`
warmup_malloc.c:174:test_find_quoted2:[42mPASS[00m

-----------------------
7 Tests 3 Failures 0 Ignored 
[41mFAIL[00m
make: *** [Makefile:20: test] Error 3

```

### make checkstyle  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make checkstyle
[0mclang-tidy --quiet *.c --
660 warnings generated.
1321 warnings generated.

```

### check clang-format  🟢 (success)
```bash
+ check_clang_format -r $(cat current_sheet)

```

### check erfahrungen.txt  🟢 (success)
```bash
+ check_erfahrungen $(cat current_sheet)

```
