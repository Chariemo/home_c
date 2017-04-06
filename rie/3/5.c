#include<stdio.h>
int main(void)
{
	long num;
	long sum = 0;
	int status;
	printf("Plwase enter an integer to be summed.");
	printf("(q to quit):");
	status = scanf ("%ld",&num);
	while(status == 1)
	{
		sum = sum + num;
		printf("Please enter next intrger (q to quit):");
		status = scanf("%ld",&num);
	}
	printf("Those integers sum to %ld.\n",sum);
	return 0;
}
