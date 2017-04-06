/*3~100 的素数  10个一行*/
#include<stdio.h>
int main (void)
{
	int num,i,flag,l;
	l = 0;
	
	for (num = 3; num <= 100; num++)
	{	
		flag =1;
		for (i = 2; i < num; i++)
		{
			if (num%i == 0)
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			l++;
			printf("%4d",num);
		
			if (l%10==0)
				printf("\n");
		}
	}
	printf ("\n");

	return 0;
}
