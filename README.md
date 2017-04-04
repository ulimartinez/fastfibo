Fast Fibonacci
===============
This is a C program that computes the n-th fibonacci number using the fast doubling algorithm. The algorithm is based on the following identity:

<a href="https://www.codecogs.com/eqnedit.php?latex=F(2n)=F(n)*[2*F(n&plus;1)-F(n)]&space;F(2n&plus;1)=F(n)^2&plus;F(n&plus;1)^2" target="_blank"><img src="https://latex.codecogs.com/gif.latex?F(2n)=F(n)*[2*F(n&plus;1)-F(n)]&space;F(2n&plus;1)=F(n)^2&plus;F(n&plus;1)^2" title="F(2n)=F(n)*[2*F(n+1)-F(n)] F(2n+1)=F(n)^2+F(n+1)^2" /></a>


The program is designed to be fast and lightweight. It has a built in custom arbitrary precission library for numbers that are very large (larger than 1.8E20).
