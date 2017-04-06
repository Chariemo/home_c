#include<stdio.h>
void main()
{	
	int x = 4,y = 0, z;
	x *= 3 + 2;
	printf("%d\n",x);
	x*=(y=(z=4));
	printf("%d",x);
}
