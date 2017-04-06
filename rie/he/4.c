/*镜像对掉*/
#include<stdio.h>
#define NUM 5
int main (void)
{
    int array[NUM], ar[1], i;
    
    printf("Please enter array[%d]:\n",NUM);
    for (i = 0; i < NUM; i++)
	scanf("%d",&array[i]);
    printf("Befoe changed:\n");
    for (i = 0; i < NUM; i++)
	printf("%d ",array[i]);

    for (i = 0; i < NUM/2; i++)
    {
	ar[1] = array[i];
	array[i] = array[NUM-i-1];
	array[NUM-i-1] = ar[1];
    }
    printf("\nChanged:\n");
    for (i = 0; i < NUM; i++)
	printf("%d ",array[i]);
    putchar('\n');
    return 0;
}
