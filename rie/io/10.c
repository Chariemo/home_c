/*尝试使用strtol()函数*/
#include<stdio.h>
#include<stdlib.h>

int main ()
{
	char number[30];
	char *end;
	long value;
	
	puts ("Enter anumber (empty line to quit):");	
	while (gets (number) && number[0] != '\n')
	{
		valuae = strtol (number, &end, 10);
		printf ("value: %ld, stopped at %s (%d)\n",value, end, *end);
		value = strtol (number, &end, 16);
		printf ("value: %ld, stopped at %s (%d)\n",value, end, *end);
		puts ("Next number:");
	}
	puts ("Bye!\n");
	
	return 0;
}
