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
  unsigned long msb = 31 - __builtin_clz(n);
  for(; msb >= 0; msb--){
    //loop stuff in here
    unsigned long long c = b << 1;
    c -= a;
    c = mt(c, a);
    b = sq(a)+sq(b);
    a = c;
    if(n>>msb&1){
      c = a+b;
      a = b;
      b = c;
    }
  }
  printf("%llu", a);
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
  int msb = 31 - __builtin_clz(n);
  for(long i = 0; i <= msb; i++){
    res *= 4;
    if(n>>i&1)
      res+=4*i+1;
  }
  return res;
}
