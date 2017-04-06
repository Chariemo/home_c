#include<stdio.h>
int main(void)
{
	int a ;
	float assets ;
	char pets[40];
	printf("enter your age ,assets,and favorit pet.\n");
	scanf("%d %f %s",&a,& assets,pets);
	printf("%d $%.2f %s\n",a,assets,pets);
	return 0;
}
