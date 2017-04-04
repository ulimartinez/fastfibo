Fast Fibonacci
===============
This is a C program that computes the n-th fibonacci number using the fast doubling algorithm. The algorithm is based on the following identity:

```math
F(2n)=F(n)*[2*F(n+1)-F(n)]
F(2n+1)=F(n)^2+F(n+1)^2
```
The program is designed to be fast and lightweight. It has a built in custom arbitrary precission library for numbers that are very large (larger than 1.8E20).
