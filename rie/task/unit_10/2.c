#include <stdio.h>

int main (void)
{
	int num = 1;
	int i = 0, j;
	unsigned int arr[num];
	while (scanf ("%u", &arr[i++]))
		num++;
	for (j = 0; j < num-1; j++)
		printf ("%u ", arr[j]);
	
	return 0;
}
