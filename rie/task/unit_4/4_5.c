/*两个数的最大公约数*/

#include <stdio.h>

int main (void)
{
	int num1, num2, min;
	register int i;
	
	puts ("Please enter two numbers: ");
	scanf ("%d %d", &num1, &num2);
	min = (num1 > num2) ? num2 : num1;
	
	printf ("%d、和%d的最大公约数:", num1, num2);	
	for (i = min; i > 0; i--)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			printf ("%d ", i);
			break;
		}
	}
	puts ("\n");
	return 0;
}
