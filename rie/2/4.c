#include<stdio.h>
#include<string.h>
int main(void)
{
	int a,b; 
	char name[40],xing[40];
	printf("enter your name and xing:\n");
	scanf("%s %s",name,xing);
	a=strlen(name);
	b=strlen(xing);
	printf("%s %s\n",name,xing);
	printf("%*d %*d",a,a,b,b);
	return 0;
}

