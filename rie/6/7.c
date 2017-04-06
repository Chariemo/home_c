#include<stdio.h>
#define SPACE ' '
int main (void)
{
	char ch ;
	
	while ((ch=getchar()) != ' \n')
	{
		if (ch == SPACE)  /*空格不变 */
			putchar(ch);
		else 
			putchar(ch +1);
		ch =getchar(); /*  打印换行字符*/
	}
	putchar(ch);
	return 0;
}
