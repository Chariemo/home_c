/*最小值*/
#include<stdio.h>
int imin(int m ,int n) {return (m < n) ? m: n;}

int main (void)
{
	int evi11,evi12;
		
	printf("Enter a pair of integers (q to quit):\n");
	while (scanf ("%d %d",&evi11,&evi12))
	{
		printf ("The lesser of %d and %d is %d.\n",
			evi11,evi12,imin(evi11,evi12));
		printf ("Enter a pair of integers (q to quit):\n");
	}
	printf ("Bye!\n");
	return 0;
}
/*	
int imin (int n, int m)
{
	return (m < n) ? m:n;
}*/
