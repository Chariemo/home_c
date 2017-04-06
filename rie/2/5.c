#include<stdio.h>
#include<float.h>
int main(void)
{
	double a = 1.0/3.0;
	float b = 1.0/3.0;
	printf("%16.4f %16.4f",a,b);
	printf("\n%16.12f %16.12f",a,b);
	printf("\n%16.16f %16.16f",a,b);
	printf("\n%16d\n",FLT_DIG);
	printf("%16d\n",DBL_DIG);
	return 0;
}

