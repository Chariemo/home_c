/* 金字塔*/
#include<stdio.h>
int main (void)
{
	int i,j,k,n,m;
	
	for (i = 1; i <= 5; i++)
	{
		if (i <= 3)
		{
			for (j = 1; j <= 15 - 2*i; j++)
				printf(" ");
			for (k = 1; k <= 2*i; k++)
				printf("*");
		}
		else
		{
			for (n = 1; n <= 2*i+3;n++)
				printf(" ");
			for (m = 1; m <= 12-2*i;m++)
				printf("*");
		}
		printf("\n");
	}
	return 0;
}
			
