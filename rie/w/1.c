/*求s = 1+（1+2）+（1+2+3）.......*/
#include<stdio.h>
int main(void)
{
	int a,b,t,s,n;
	s = 0;
	printf("n=");
	scanf("%d",&n);
	for (a = 1; a <= n; a++)
	{	
		b = 0;
		for (t = 1; t <= a; t++)
			b += t;
		s += b;
	}
	
	printf("s = %d\n",s);
	return 0;
}
