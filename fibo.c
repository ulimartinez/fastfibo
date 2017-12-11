#include "mt.h"
#include "bignum.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
/****************************
F(2n) = F(n)*[2*F(n+1)-F(n)]
F(2n+1) = F(n+1)^2 + F(n)^2
*****************************/
int main(int argc, char **argv){
  char *last;
  long n = strtol(argv[1], &last, 10);
  //get the number n
  if(*last){
    printf("Must specify just an integer");
    exit(EXIT_FAILURE);
  }
  bigInt a = {a.length = 0};
  bigInt b = {b.length = 0};
  //initialize a and b nig numbers to 0
  long msb = 31 - __builtin_clz(n);
  //the position of the most significant bit in n
  while(msb >=0){
    //for each bit
    bigInt c = {c.length = b.length};
    memcpy(c.number, b.number, b.length * sizeof(long long));
    //copy b into c
    biglshift(&c);//2b
    c = bigsub(c, a);//2b-a
    c = bigmt(c, a);//a*c
    b = addBigInts(bigmt(a, a),bigmt(b, b));//a^2 + b^2
    a = c;
    if(n>>msb&1){
      c = addBigInts(a,b);
      a = b;
      b = c;
    }
    msb--;
  }
  printf("%llu\n", a.number[0]);
}
unsigned long long sq(unsigned long long n){
  unsigned long long res = 0;
  unsigned long long i = n;
  unsigned long count = 0;
  while(i > 0){
    if(i&1){
      res += n << count;
    }
    i = i >> 1;
    count++;
  }
  return res;
}
