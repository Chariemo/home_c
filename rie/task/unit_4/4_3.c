/*500内的水仙花数*/

#include <stdio.h>
#include <math.h>
#define N 500
int main (void)
{
	register int temp, unit, dec, hun;
	
	printf ("%d内的水仙花数:\n", N);
	for (temp = 100; temp < N; temp++)
	{
		unit = temp%100%10;
		dec = temp%100/10;
		hun = temp/100;
		if (temp == pow (unit,3)+pow (dec,3)+pow (hun,3))
			printf ("%d ", temp);
	}
	puts ("\n");
	
	return 0;
}
