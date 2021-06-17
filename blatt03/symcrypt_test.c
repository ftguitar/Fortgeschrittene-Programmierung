#include "../unity/unity.h"
#include "./symcrypt_lib.h"
#include "stdio.h"
#include "string.h"

void setUp(void) {}

void tearDown(void) {}

void test_encrypt_char_1(void) {
  TEST_ASSERT_EQUAL('3', encrypt_char('I', 'i'));
}

void test_encrypt_char_2(void) {
  TEST_ASSERT_EQUAL('l', encrypt_char(' ', 'l'));
}

void test_encrypt_char_3(void) {
  TEST_ASSERT_EQUAL('K', encrypt_char('a', 'i'));
}

void test_decrypt_char_1(void) {
  TEST_ASSERT_EQUAL('I', decrypt_char('3', 'i'));
}

void test_decrypt_char_2(void) {
  TEST_ASSERT_EQUAL(' ', decrypt_char('l', 'l'));
}

void test_decrypt_char_3(void) {
  TEST_ASSERT_EQUAL('a', decrypt_char('K', 'i'));
}

void test_encrypt_1(void) {
  char message[] = "hallo";
  char secret[] = "code";
  char encrypted[6];
  encrypt(message, secret, encrypted);
  TEST_ASSERT(0 == strcmp("LQQRS", encrypted));
}

void test_encrypt_2(void) {
  char message[] = "Programmieren in C";
  char secret[] = "eNcrYpt";
  char encrypted[19];
  encrypt(message, secret, encrypted);
  TEST_ASSERT(0 != strcmp("Z ist die falsche Antwort", encrypted));
}

void test_decrypt_1(void) {
  char message[] = "LQQRS";
  char secret[] = "code";
  char decrypted[6];
  decrypt(message, secret, decrypted);
  TEST_ASSERT(0 != strcmp("hallo!", decrypted));
}

void test_decrypt_2(void) {
  char message[] = "Das ist nicht Python";
  char secret[] = "eNcrYpT";
  char decrypted[21];
  decrypt(message, secret, decrypted);
  TEST_ASSERT(0 != strcmp("Programmieren in C ist was anderes!", decrypted));
}

int main(int argc, char *argv[]) {
  UNITY_BEGIN();
  RUN_TEST(test_encrypt_char_1);
  RUN_TEST(test_encrypt_char_2);
  RUN_TEST(test_encrypt_char_3);
  RUN_TEST(test_decrypt_char_1);
  RUN_TEST(test_decrypt_char_2);
  RUN_TEST(test_decrypt_char_3);
  RUN_TEST(test_encrypt_1);
  RUN_TEST(test_encrypt_2);
  RUN_TEST(test_decrypt_1);
  RUN_TEST(test_decrypt_2);
  return UNITY_END();
}
