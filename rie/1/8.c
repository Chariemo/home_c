#include<stdio.h>
#include<limits.h>
#include<float.h>
int main(void)
{
	printf("some sumber limits for this system:\n");
	printf("biggest int:%d \n",INT_MAX);
	printf("smallest unsigned long:%lld \n",LLONG_MIN);
	printf("one byte =%d bites on this system.\n",CHAR_BIT);
	printf("largest double:%e \n",DBL_MAX);
	printf("smallest normal float :%e\n",FLT_MIN);
	printf("float precision = %d digits\n",FLT_DIG);
	printf("float epsilon = %e \n",FLT_EPSILON);
	return 0;
}
