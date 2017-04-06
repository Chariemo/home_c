#include<stdio.h>
#include<string.h>
#define PRAISE "What a wuper marvelous name!"
int main(void)
{
	int a;
	int b;
	char name[40];
	printf("What's your name?\n");
	scanf("%s",name);
	printf("Hello,%s.%s\n",name,PRAISE);
	b=strlen(name);
	printf("Your name of %d letters occupies %ld memory cells.\n",                          b,sizeof name);
	a=strlen(PRAISE);
	printf("The phrase of praisse has %d letters",a);
	printf("and occupies %ld memry cells.\n",sizeof PRAISE);
	return 0;
}
