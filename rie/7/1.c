/*sum = 1-2+3-4...n*/
#include<stdio.h>
#include<math.h>
int main (void)
{
	int sum,n,i;
	printf("n=");
	scanf("%d",&n);
	sum= 0;
	i = 1;
	while ( i <=n)
	{
		sum += pow(-1,i+1)*i;
		++i;
	}
	printf("sum = %d\n",sum);
	return 0 ;
}
