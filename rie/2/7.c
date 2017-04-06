#include<stdio.h>
int main(void)
{
	int a = 1;
	while ( a < 21 )
	{
		printf("%4d %6d \n",a,a*a);
		a= a+ 1;
	}
	return 0;
}
