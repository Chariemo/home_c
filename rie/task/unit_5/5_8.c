/* 整数数列的重新排列(同行向右递增，同列向下递增 */

#include <stdio.h>
#define ROWS 3
#define COLS 3

int main (void)
{
	int arr[ROWS][COLS];
	register int r, c, i, j;
	int temp, change;
	
	printf ("Enter %d*%d array:", ROWS, COLS);
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			scanf ("%d", &arr[r][c]);
	
	puts ("Before sorted:");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf ("%d ",arr[r][c]);
		putchar ('\n');
	}
	
	for (r = 0; r < ROWS; r++)
	{
		change = 1;
		for (i = 0; i < COLS && change; i++)
		{
			change = 0;
			for (j = 0; j < COLS-i-1; j++)
				if (arr[r][j] > arr[r][j+1])
				{
					temp = arr[r][j];
					arr[r][j] = arr[r][j+1];
					arr[r][j+1] = temp;
					change = 1;
				}
		}
	}

	for (c = 0; c < COLS; c++)
	{
		change = 1;	
		for (i = 0; i < ROWS && change; i++)
		{
			change = 0;
			for (j = 0; j < ROWS-i-1; j++)
				if (arr[j][c] > arr[j+1][c])
				{
					temp = arr[j][c];
					arr[j][c] = arr[j+1][c];
					arr[j+1][c] = temp;
					change =1;
				}
		}
	}
	
	puts ("After sorted:");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf ("%d ", arr[r][c]);
		putchar('\n');
	}
	return 0;
}
