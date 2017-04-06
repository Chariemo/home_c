#include <stdio.h>
#include <stdlib.h>

#define NUM 4
void input (int [], int);
void output (int [], int);
int mycomp (const void *, const void *);

int main (void)
{
	int arr[NUM];
	printf ("Enter %d numbers: ", NUM);
	
	input (arr, NUM);
	
	puts ("Before sorted:");
	output (arr, NUM);

	qsort (arr, NUM, sizeof (int), mycomp);
	
	puts ("\nAfter sored:");
	output (arr, NUM);
	
	return 0;
}

void input (int arr[], int n)
{
	register int i;	
	for (i = 0; i < n; i++)
		scanf ("%d", &arr[i]);
}

void output (int arr[], int n)
{
	register int i;
	for (i = 0; i < n; i++)
		printf ("%d ", arr[i]);
	putchar ('\n');
}

int mycomp (const void * p1, const void * p2)
{
	const int * a1 = (const int *) p1;
	const int * a2 = (const int * ) p2;
	if (*a1 == *a2)
		return 0;
	else if (*a1 > *a2)
		return 1;
	else
		return -1;
}
	
