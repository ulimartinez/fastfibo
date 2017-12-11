#include "bignum.h"
#include <stdlib.h>
#include <stdio.h>
bigInt addBigInts(bigInt a, bigInt b){
  unsigned int length = a.length > b.length? a.length: b.length;//the number with most digits
  bigInt c = {c.length = 0};
  unsigned short carry = 0;
  int i;
  for(i = 0; i < length; i++){
    c.number[i] = carry + a.number[i] + b.number[i];
    if(c.number[i] < a.number[i]){//overflow occured
	carry = 1;
    }
    else{
      carry = 0;
    }
    c.length++;
  }
  if(carry){
    c.number[i++] = carry;
    c.length = i;
  }
  return c;
}
bigInt bigDouble_old(bigInt a){
  return addBigInts(a, a);
}

/* bigInt bigmt(bigInt u, bigInt v){ */
/*    unsigned long long k, t; */
/*    int i, j; */
/*    bigInt w = {w.length = u.length}; */

/*    for (j = 0; j < v.length; j++) { */
/*       k = 0; */
/*       for (i = 0; i < u.length; i++) { */
/* 	t = mt(u.number[i],v.number[j]) + w.number[i + j] + k; */
/*          w.number[i + j] = t;          // (I.e., t & 0xFFFF). */
/*          k = t >> (sizeof(k)*4); */
/*       } */
/*       w.number[j + u.length] = k; */
/*    } */
/*    return w; */
/* } */
void biglshift(bigInt* a){;
  unsigned short carry = 0;
  int i;
  unsigned long long tmp;
  unsigned int length = a->length;
  for(i = 0; i < length; i++){
    tmp = a->number[i];
    a->number[i] = (a->number[i] << 1) + carry;
    if(a->number[i] <= tmp){//overflow occured
	carry = 1;
    }
    else{
      carry = 0;
    }
  }
  if(carry){
    a->number[i++] = carry;
    a->length = i;
  }
}
void bigrshift(bigInt* a){;
  unsigned long long carry = 0;
  int i;
  unsigned int length = a->length;
  unsigned long long tmp = a->number[length-1];
  if(tmp==1)
    a->length-=1;
  for(i = length-1; i >= 0; i--){
    tmp = a->number[i];
    tmp >>= 1;
    if(a->number[i] & 1){
      a->number[i] = tmp+carry;
      carry = MSB;
    }
    else{
      a->number[i] = tmp+carry;
      carry = 0;
    }
  }
}
short bigEqZero(bigInt a){
  return a.length <= 1 && a.number[0] == 0? 1: 0;
}
bigInt bigmt(bigInt a, bigInt b){
  bigInt res = {res.length = 1, res.number[0] =0};
  while(!bigEqZero(b)){
    if(b.number[0]&1){
      res = addBigInts(res, a);
    }
    biglshift(&a);
    bigrshift(&b);
  }
  return res;
}
char* toBCD(bigInt a){
  unsigned int size = 100;
  char* bcd = calloc(size+1, 1);
  bcd[size]=0;
  for(int i = a.length-1; i>=0; i--){
    for(int j = 8*sizeof(a.number[0])-1; j>=0; j--){
      char val = (a.number[i]>>j)&1;
      for(int k = 0; k<size-1;k++){
	if(bcd[k]>4)
	  bcd[k] = (bcd[k]+3)&0x0F;
      }
      for(int k = size-2; k>=1;k--){
	bcd[k] <<= 1;
	bcd[k] += (bcd[k-1]>>3)&1;
	bcd[k] &= 0x0F;
      }
      bcd[0] <<=1;
      bcd[0] += val;;
      bcd[0] &= 0x0F;
    }
  }
  return bcd;
}
bigInt bigsub(bigInt a, bigInt b){
  unsigned long long carry = 1;
  for(int i = 0; i < b.length; i++){
    b.number[i] = ~b.number[i];
    if(b.number[i] == -1){
      b.number[i] += carry;
      carry = 1;
    }
    else{
      b.number[i]+= carry;
      carry = 0;
    }
  }
  return addBigInts(a, b);
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
