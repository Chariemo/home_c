#include<stdio.h>
int main(void)
{
	printf("Type int has a size of %lu bytes.\n",sizeof(int));
	printf("Type char has a size of %lu bytes.\n",sizeof(char));
	printf("Type long has a size of %lu bytes.\n",sizeof(long));
	printf("Type double has a size of %lu bytes.\n",sizeof(double));
	printf("Type float has a size of %lu bytes.\n",sizeof(float));
	printf("Type long double has a size of %lu bytes.\n",sizeof(long double));
	printf("Type short has a size of %lu bytes.\n",sizeof(short));
	printf("Type long long has a size of %lu bytes.\n",sizeof(long long));
	return 0;


}
