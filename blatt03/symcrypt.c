#include "stdio.h"
#include "string.h"
#include "symcrypt_lib.h"

int main(int argc, char *argv[]) {
  if (argc == 4 && 0 == strcmp("encrypt", argv[1])) {
    char encrypted[5000];
    encrypt(argv[3], argv[2], encrypted);
    printf("'%s'\n", encrypted);
    return 0;
  }
  if (argc == 4 && 0 == strcmp("decrypt", argv[1])) {
    char decrypted[5000];
    decrypt(argv[3], argv[2], decrypted);
    printf("'%s'\n", decrypted);
    return 0;
  } else {
    printf("USAGE\n  symcrypt [encrypt|decrypt] SECRET MESSAGE\n\n");
    printf("  Encrypts or decrypts a MESSAGE using a shared SECRET.\n\n");
    return 1;
  }
  // printf("%s\n%s\n%s\n", argv[1], argv[2], argv[3]);
}
