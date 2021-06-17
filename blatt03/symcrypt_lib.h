/* Author: Frederick Trach <frederick.trach@students.uni-freiburg.de>
 * Copyright
 */

char encrypt_char(char m, char s);
char decrypt_char(char m, char s);
void encrypt(char *message, char *secret, char *encrypted);
void decrypt(char *message, char *secret, char *decrypted);
int main(int argc, char *argv[]);
