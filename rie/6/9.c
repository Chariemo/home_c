#include<stdio.h>
#include<ctype.h>
int main(void)
{
	char ch;
	
	while ((ch = getchar()) != ' \n')
	{
		if (isalnum(ch))
			putchar(isupper(ch));
		else
			putchar(ch);
	}
	putchar(ch);
	return 0;
}
