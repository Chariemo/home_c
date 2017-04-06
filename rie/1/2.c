#include<stdio.h>
#include<inttypes.h>
int main(void)
{
	int16_t me16;
	me16=4393;
	printf("First,assume int16_t is short:");
	printf("me16=%hd\n",me16);
	printf("Next,let's not make any assumeption.\n");
	printf("Instead,use a \"macro\"from inttypes.h:");
	printf("me16 = %" PRID16 "\n",me16);
	return 0;
}
