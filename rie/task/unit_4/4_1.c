/* s=1!+3!+...+97!+99! */

#include <stdio.h>

int main (void)
{
	register int sum = 0, node, i, j;
		
	for (i = 1; i <= 99; i += 2)
	{
		node = 1;
		for (j = 1; j <= i; j++)
			node *= j;
		sum += node;
	}
	printf ("s = 1!+3!+...+99! = %d\n", sum);
	return 0;
}
		
