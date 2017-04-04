#include "bignum.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
int main(){
  bigInt d = {d.number[0] = 2, d.length = 1};
  bigInt c = {c.number[0] = 2, c.length = 1};
  bigInt a = bigmt(d, c);
  printf("%llu times %llu is %llu\n", d.number[0], c.number[0], a.number[0]);
}
