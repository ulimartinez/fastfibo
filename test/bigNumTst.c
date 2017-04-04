#include "bignum.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void printBits(unsigned long long n);
void toChars(char* bcd);
int main(){
  bigInt b = {b.number[0] = 0, b.number[1] = 1, b.length = 2};
  bigInt c = {c.number[0] = 1, c.length = 1};
  bigInt a = bigsub(b, c);
  printf("%llu minus %llu is %llu\n", b.number[0], c.number[0], a.number[0]);
}
void toChars(char* bcd){
  for(int i = 0; i < 100; i++){
    bcd[i] += '0';
  }
}
void printBits(unsigned long long n){
  char* str = (char*)malloc(64);
  for(int i = 8*sizeof(n)-1; i >= 0; i--){
    if(n&1){
      str[i] = '1';
    }
    else
      str[i] = '0';
    n>>=1;
  }
  printf("%s\n", str);
}
