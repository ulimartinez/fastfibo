#define MSB 9223372036854775808ULL
struct bigInt_s{
  unsigned int length;
  unsigned long long number[];
};
typedef struct bigInt_s bigInt;
bigInt addBigInts(bigInt a, bigInt b);
void biglshift(bigInt* a);
void bigrshift(bigInt* a);
bigInt bigsub(bigInt a, bigInt b);
unsigned long long mt(unsigned long long a, unsigned long long b);
bigInt bigmt(bigInt a, bigInt b);
char* toBCD(bigInt a);
