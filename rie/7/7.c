/*求pi的近似值*/
#include<stdio.h>
#include<math.h>
int main (void)
{
	int mu = 1;
	int a = -1;
	float s, t;
	t = 1.0;
	while (abs(t) >= 1e-6)
	{
		s += t;
		mu += 2;
		t = 1.0/mu *a;
		a = -a;
	}
	printf("pi = %f",s * 4);
	return 0;
}
