#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 3

typedef struct names 
{
	char first[20];
	char last[20];
} NA, *PNA;

void input (NA [], int );
void output (NA [], int);
int mycomp (const void *, const void *);

int main (void)
{
	NA arr[NUM];
	input (arr, NUM);
	puts ("Before Sorted: ");
	output (arr, NUM);
	qsort (arr, NUM, sizeof (NA), mycomp);
	puts ("After Sorted: ");
	output (arr, NUM);
	return 0;
}

void input (NA arr[], int n)
{
	register int index;
	printf ("Enter %d names:\n", n);
	
	for (index = 0; index < n; index++)
	{
		printf ("NO.%d's name: ", index+1);
		scanf ("%s %s", arr[index].first, arr[index].last);
		putchar ('\n');
	}
}

void output (NA arr[], int n)
{
	register int index;
	for (index = 0; index < n; index++)
		printf ("NO.%d: %s %s\n", index+1, arr[index].first, arr[index].last);
}

int mycomp (const void * p1, const void * p2)
{
	int temp;
	const NA * a1 = (const void *)p1;
	const NA * a2 = (const void *)p2;
	temp = strcmp (a1->last, a2->last);
	
	if (temp != 0)
		return temp;
	else 
		return strcmp (a1->first, a2->first);
}
