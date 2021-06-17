# blatt01 (16.0 / 16.0)


Sehr gut! 

## Build Log  🟢 (success)
### clone  🟢 (success)
```bash
Initialized empty Git repository in /drone/src/.git/
+ git fetch origin +refs/heads/master:
From https://git.inpro.informatik.uni-freiburg.de/2021-ss-c-kurs/tf166
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
+ git checkout cb40db191fd85ce68d0c2b26268e297f92523ea6 -b master
Already on 'master'

```

### retrieve current sheet  🟢 (success)
```bash
+ export SHEET=$(curl https://courses.inpro.informatik.uni-freiburg.de/2021-SS/c-kurs/active_exercises | head -n 1)
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0100     7  100     7    0     0    118      0 --:--:-- --:--:-- --:--:--   118
+ echo Currently active exercise directory: $SHEET
Currently active exercise directory: blatt01
+ echo $SHEET > current_sheet

```

### make compile  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mgcc -c hello.c -o hello.o
gcc hello.o -o hello
gcc -c bye.c -o bye.o
gcc bye.o -o bye

```

### make test  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make test
[0mecho "Everything is ok. There are no tests, yet."
Everything is ok. There are no tests, yet.

```

### make checkstyle  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make checkstyle
[0mclang-tidy --quiet *.c --
231 warnings generated.
462 warnings generated.

```

### check clang-format  🟢 (success)
```bash
+ check_clang_format -r $(cat current_sheet)

```

### check erfahrungen.txt  🟢 (success)
```bash
+ check_erfahrungen $(cat current_sheet)

```
