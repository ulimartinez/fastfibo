#include "mt.h"
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int main(int argc, char **argv){
  char *last;
  long n = strtol(argv[1], &last, 10);
  if(*last){
    printf("Must specify just an integer");
    exit(EXIT_FAILURE);
  }
  unsigned long long a = 0;
  unsigned long long b = 1;
  long msb = 31 - __builtin_clz(n);
  while(msb >=0){
    //loop stuff in here
    //printf("msb: %lu\n", msb);
    unsigned long long c = b << 1;
    c -= a;
    //printf("%llu times %llu is ", c, a);
    c = mt(c, a);
    //printf("%llu\n", c);
    //printf("%llu squared plus %llu squared is ", a, b);
    b = sq(a)+sq(b);
    //printf("%llu\n", b);
    a = c;
    //printf("a is %llu, b is %llu\n", a, b);
    if(n>>msb&1){
      c = a+b;
      a = b;
      b = c;
      //printf("after adding once a is %llu, b is %llu\n", a, b);
    }
    msb--;
  }
  printf("%llu\n", a);
}
unsigned long long mt(unsigned long long a, unsigned long long b){
  unsigned long long res = 0;
  while (b != 0){
    if (b&1){
      res = res + a;  // Add a to result if b is odd .
    }
    a<<=1;                    // Left shifting the value contained in 'a' by 1
                                  // Multiplies a by 2 for each loop
    b>>=1;                    // Right shifting the value contained in 'b' by 1.
  }
  return res;
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
