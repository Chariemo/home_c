/*100内的完数*/

#include <stdio.h>
#define N 100

int main (void)
{
	register int temp, div, sum;
	
	printf ("%d内的完数: ", N);
	for (temp = 1; temp <= N; temp++)
	{
		sum = 0;
		for (div = 1; div < temp; div++)
			if (temp%div == 0)
				sum += div;
		if (temp == sum)
			printf ("%d ", temp);
	}
	puts ("\n");
	return 0;
}
