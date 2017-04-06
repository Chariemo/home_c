#include<stdio.h>
void main ()
{
    int k = 2, m = 4, n = 6;
    int * p1 = &k, * p2 = &m, * p3 = &n;
    *p1 = *p3; *p3 = *p1;
    if (p1 == p3)  p1 = p2;
    printf("p1 = %d p2 = %d p3 = %d\n", *p1,*p2,*p3);
}
