#include <stdio.h>
#include <assert.h>

#include "crypto_verify_32.h"

int crypto_verify_32(const unsigned char *x,const unsigned char *y)
{
  unsigned int differentbits = 0;
#define F(i) differentbits |= x[i] ^ y[i];
  F(0)
  F(1)
  F(2)
  F(3)
  F(4)
  F(5)
  F(6)
  F(7)
  F(8)
  F(9)
  F(10)
  F(11)
  F(12)
  F(13)
  F(14)
  F(15)
  F(16)
  F(17)
  F(18)
  F(19)
  F(20)
  F(21)
  F(22)
  F(23)
  F(24)
  F(25)
  F(26)
  F(27)
  F(28)
  F(29)
  F(30)
  F(31)
  return (1 & ((differentbits - 1) >> 8)) - 1;
}


int crypto_hash_sha512(unsigned char *out,const unsigned char *in,unsigned long long inlen) {
//  SHA512(in,inlen,out);
  return 0;
}

void randombytes(unsigned char * r,unsigned long long l) {
  FILE *fp = fopen("/dev/urandom", "r");  //TODO Remove hard-coded use of /dev/urandom.
  size_t bytes_read = fread(r, 1, l, fp);
  assert(bytes_read == l);
  fclose(fp);
}
