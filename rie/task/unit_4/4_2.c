/*求2/1, 3/2, 5/3, 8/5　前10项和*/

#include <stdio.h>
int main (void)
{
	register int i, zi = 2, mu = 1;
	float sum = 0.0;
	
	for (i = 1; i <= 10; i++)
	{
		sum += 1.0*zi/mu;
		mu = zi;
		zi += i;
	}
		
	printf ("s = %f\n", sum);
	return 0;
}
