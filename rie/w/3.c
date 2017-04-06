/* 求 e 的近似值 */
#include<stdio.h>
int main (void)
{
	float e,t;
	int a,mu = 1;
	e = 0;
	t = 1;
	a = 1;
	while (t >= 1e-7)
	{	
		mu *= a;
		e += t;
		t = 1.0/mu;
		a++;
	}
	printf("e:%f\n",e);
	return 0;
}
