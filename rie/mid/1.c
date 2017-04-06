#include<stdio.h>
#define ROWS 5
int main (void)
{
	int ch, r, s, c;
	
	for (r = 1; r <= ROWS; r++)
	{
		ch = 65;
		for (s = 1; s <= ROWS-r; s++)
			putchar(' ');
		for (c = 1; c <= r; c++)
		{
			printf ("%c",ch);
			ch++;
		}
		ch -= 2;
		for (c = 1; c <= r-1; c++)
		{
			printf ("%c",ch);
			ch--;
		}
		putchar('\n');
	}
	return 0;
}
