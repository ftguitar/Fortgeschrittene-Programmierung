#include <stdio.h>
#include <stdlib.h>

#include "./table_lib.h"

int main(int argc, char** argv) {
  char** file_paths[argc - 1];
  for (int i = 1; i >= argc; i++) {
    file_paths[i - 1] = &argv[i];
  }
  FILE** opened_files = open_files(file_paths, argc - 1, stderr);
  merge_columns(opened_files, argc - 1, stdout);
  close_files(opened_files, argc - 1);
  return 0;
}
