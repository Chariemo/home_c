/* 求 1-1／2+1／3 -1/4...*/
#include<stdio.h>
int main (void)
{
	float t,s;
	int mu,a;
	a = 1;
	s = 0;
	t = 0;
	
	for (mu = 1;mu <= 100;mu++)
	{
		t = 1.0/mu*a;
		s += t;
		a = -a;
	}
	printf("s = %f\n",s);
	return 0;
}
