#include<stdio.h>
int main(void)
{
	int a = sizeof(int);
	int b = sizeof(short);
	int c = sizeof(long);
	int d = sizeof(double);
	int e = sizeof(char);
	printf("int short long double char  has %d %d %d %d %d bytes.\n",a,b,c,d,e);
//	printf("Type int has a size of %u bytes.\n",sizeof(int));
//	printf("Type short has a size of %u bytes.\n",sizeof(short));
//	printf("Type long has a size of %u bytes.\n",sizeof(long));
//	printf("Type double has a size of %u bytes.\n",sizeof(double));
	return 0;
}
