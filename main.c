#include <stdio.h>
int crypto_sign(
    unsigned char *sm, unsigned long long *smlen,
    const unsigned char *m, unsigned long long mlen,
    const unsigned char *sk
);
int crypto_sign_keypair(unsigned char *pk,unsigned char *sk);

int crypto_sign_open(
    unsigned char *m,unsigned long long *mlen,
    const unsigned char *sm,unsigned long long smlen,
    const unsigned char *pk
);

int main() {
  unsigned char public_key[32], private_key[64], seed[32], scalar[32];
  unsigned char other_public_key[32], other_private_key[64];
  unsigned char shared_secret[32], other_shared_secret[32];
  unsigned char signature[64];

  int i;

  const unsigned char message[] = "Hello, world!";
  const int message_len = sizeof(message)-1;

  /* create a random seed, and a keypair out of that seed */
  crypto_sign_keypair(public_key, private_key);

  unsigned long long slen = 64;
  /* create signature on the message with the keypair */
  crypto_sign(signature, &slen, message, message_len, private_key);

  unsigned long long mlen = 64;
  /* verify the signature */
  if (crypto_sign_open(signature, &mlen, message, message_len, public_key)) {
    printf("successfully!\n");
    return 0;
  } else {
    printf("failed!\n");
    return 1;
  }
}
