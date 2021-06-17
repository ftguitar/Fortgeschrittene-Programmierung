#include "./symcrypt_lib.h"
#include "stdio.h"
#include "string.h"

char encrypt_char(char m, char s) {
  m -= 32;
  s -= 32;
  int intern_result = m + s;
  if (intern_result >= 95) {
    intern_result -= 95;
  }
  intern_result += 32;
  char result = intern_result;
  return result;
}

char decrypt_char(char m, char s) {
  m -= 32;
  s -= 32;
  int intern_result = m - s;
  if (intern_result < 0) {
    intern_result += 95;
  }
  intern_result += 32;
  char result = intern_result;
  return result;
}

void encrypt(char *message, char *secret, char *encrypted) {
  int message_counter = 0;
  int secret_counter = 0;
  size_t message_len = strlen(message);
  size_t secret_len = strlen(secret);
  while (message_counter < message_len) {
    encrypted[message_counter] =
        encrypt_char(message[message_counter], secret[secret_counter]);
    message_counter++;
    secret_counter++;
    if (secret_counter >= secret_len) {
      secret_counter = 0;
    }
  }
}

void decrypt(char *message, char *secret, char *decrypted) {
  int message_counter = 0;
  int secret_counter = 0;
  size_t message_len = strlen(message);
  size_t secret_len = strlen(secret);
  while (message_counter < message_len) {
    decrypted[message_counter] =
        decrypt_char(message[message_counter], secret[secret_counter]);
    message_counter++;
    secret_counter++;
    if (secret_counter >= secret_len) {
      secret_counter = 0;
    }
  }
}
