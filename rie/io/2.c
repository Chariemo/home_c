/*读取一个名字*/
#include<stdio.h>
#define MAX 81
int main (void)
{
	char name [MAX];
	char * ptr;
	
	printf ("Hi,what's your name?\n");
	ptr = gets (name);
	printf ("%s? Ah! %s!\n",name, ptr);
	printf ("%p\n", *ptr);
	printf ("%p\n", *ptr + 1); 

	return 0;
}
