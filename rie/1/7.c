#include<stdio.h>
#include<string.h>
#define PRAISE "what a super marvelous name!"
int main(void)
{	
	char name[40];
	printf("what's your name?\n");
	scanf("%s",name);
	printf("hello,%s.%s.\n",name,PRAISE);
	printf("your name of %ld letters occupies %ld memory cells.\n",strlen(name),sizeof name);
	printf("the phrase of praise has %ld letters",strlen(PRAISE));
	printf("and occupies %ld memory cells.\n",sizeof PRAISE);
	return 0;
}
