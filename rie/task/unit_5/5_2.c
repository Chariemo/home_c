/*找二维数组的“鞍点”*/

#include <stdio.h>
#define ROWS 3
#define COLS 4

int main (void)
{
	int arr[ROWS][COLS], max, count = 0, temp, test = 1;
	register int r, c, i;
	printf ("Please enter %d*%d array:", ROWS, COLS);
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			scanf ("%d", &arr[r][c]);
	
	for (r = 0; r < ROWS; r++)
	{
		max = arr[r][0];
		temp = 0;
		for (c = 1; c < COLS; c++)
		{
			if (max < arr[r][c])
			{
				max = arr[r][c];
				temp = c;
			}
		}
		for (i = 0; i < ROWS; i++)
			if (arr[i][temp] < arr[r][temp])
			{
				test = 0;
				break;
			}
		if (test == 1)
			printf ("鞍点%d: %d\n", ++count, arr[r][temp]);
		test = 1;	
	}
	
	return 0;
}			
