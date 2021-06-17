# blatt05 (13.0 / 16.0)


Ich hoffe du warst bei nem Tutorat und hast die Funktion inzwischen verstanden?

test_vec_push kontrolliert nicht was gepushed wurde (-0.5)

bei vec_min_between kontrollierst du nicht ob from überhaupt in der Array liegt (-0.5)
(-2) weil die input bei statistics nicht funktioniert

## Build Log  🔴 (failure)
### clone  🟢 (success)
```bash
Initialized empty Git repository in /drone/src/.git/
+ git fetch origin +refs/heads/master:
From https://git.inpro.informatik.uni-freiburg.de/2021-ss-c-kurs/tf166
 * branch            master     -> FETCH_HEAD
 * [new branch]      master     -> origin/master
+ git checkout 2048e3cf759c9faef2b2521dbf0f30aba6a4e3cc -b master
Already on 'master'

```

### retrieve current sheet  🟢 (success)
```bash
+ export SHEET=$(curl https://courses.inpro.informatik.uni-freiburg.de/2021-SS/c-kurs/active_exercises | head -n 1)
  % Total    % Received % Xferd  Average Speed   Time    Time     Time  Current
                                 Dload  Upload   Total   Spent    Left  Speed
  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0  0     0    0     0    0     0      0      0 --:--:-- --:--:-- --:--:--     0100     7  100     7    0     0    116      0 --:--:-- --:--:-- --:--:--   114
+ echo Currently active exercise directory: $SHEET
Currently active exercise directory: blatt05
+ echo $SHEET > current_sheet

```

### make compile  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make compile
[0mgcc  -g -c vec_test.c 
gcc  -g -c ../unity/unity.c -o ../unity/unity.o
gcc  -g -c vec.c
gcc  -g vec_test.o -o vec_test ../unity/unity.o vec.o
gcc  -g -c statistics.c
gcc  -g statistics.o vec.o -o statistics

```

### make test  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make test
[0m./vec_test
vec_test.c:75:test_vec_at:[42mPASS[00m
vec_test.c:76:test_vec_length:[42mPASS[00m
vec_test.c:77:test_vec_capacity:[42mPASS[00m
vec_test.c:78:test_vec_push:[42mPASS[00m
vec_test.c:79:test_vec_pop_1:[42mPASS[00m
vec_test.c:80:test_vec_pop_2:[42mPASS[00m
vec_test.c:81:test_vec_min_between:[42mPASS[00m
vec_test.c:82:test_vec_sort:[42mPASS[00m

-----------------------
8 Tests 0 Failures 0 Ignored 
[42mOK[00m

```

### make checkstyle  🟢 (success)
```bash
+ cd $(cat current_sheet)
+ make checkstyle
[0mclang-tidy --quiet *.c --
458 warnings generated.
1037 warnings generated.
1698 warnings generated.

```

### check clang-format  🔴 (failure)
```bash
+ check_clang_format -r $(cat current_sheet)
--- blatt05/vec.h	(original)
+++ blatt05/vec.h	(reformatted)
@@ -6,11 +6,11 @@
 
 /* Struct Declaration. The actual struct definition is hidden in `vec.c`.
  *
- * This prevents people, who are using our vector library, to directly 
- * access the fields of this struct, like `capacity`. The only way to 
+ * This prevents people, who are using our vector library, to directly
+ * access the fields of this struct, like `capacity`. The only way to
  * interact with the vector is via the functions declared in this header.
  *
- * In other words: people using this library are not able to do stupid 
+ * In other words: people using this library are not able to do stupid
  * stuff like changing the vector's capacity without also reallocating the
  * memory area of the vector.
  */
@@ -19,7 +19,7 @@
 /* Allows us to write `Vec` instead of `struct Vec`. */
 typedef struct Vec Vec;
 
-/* Returns a pointer to a freshly allocated vector of length 0 and 
+/* Returns a pointer to a freshly allocated vector of length 0 and
  * capacity 1.
  * Returns NULL if we run out of memory.
  */
@@ -40,14 +40,14 @@
 /* Append a single element `x` at the end of the vector `xs`.
  *
  * If the vector's length is equal to its capacity, the vector's data is
- * reallocated at the double of its capacity to allow for amortized 
+ * reallocated at the double of its capacity to allow for amortized
  * constant runtime.
  *
  * Returns `false` if we run out memory, otherwise `true`.
  */
 bool vec_push(Vec *xs, int x);
 
-/* Remove the last element of vector `xs` if it exists. Otherwise do 
+/* Remove the last element of vector `xs` if it exists. Otherwise do
  * nothing.
  *
  * If the resulting vector's length is half of its capacity, the vector's
@@ -58,10 +58,10 @@
 /* Print the address, length, capacity, and elements of `xs`. */
 void vec_print(Vec *xs);
 
-/* Returns a pointer to the smallest element in `xs` which has an index 
+/* Returns a pointer to the smallest element in `xs` which has an index
  * greater or equal to `begin` but less than `end`.
  *
- * If the range between `begin` and `end` is invalid or contains no 
+ * If the range between `begin` and `end` is invalid or contains no
  * elements,
  * then the NULL-pointer is returned.
  */

```

### check erfahrungen.txt  🟢 (success)
```bash
+ check_erfahrungen $(cat current_sheet)

```
