#include<stdio.h>
#define SEC_PER_MIN 60
int main(void)
{
	long sec, min, left;
	
	printf("Convert seconds to minutes and seconds!\n");
	printf("Enter the number of seconds (<=0 to quit):\n");
	scanf("%ld",&sec);
	while (sec>0)
	{
		min = sec / SEC_PER_MIN ;
		left = sec % SEC_PER_MIN ;
		printf("%ld seconds is %ld mintutes,%ld seconds.\n",sec,min,left);
		printf("Enter next value (<=0 to quit ):\n");
		scanf("%ld",&sec);
	}	
	printf("Done!\n");
	return 0;
}
