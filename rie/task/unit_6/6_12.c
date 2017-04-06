/*　调用函数将矩阵转置　*/
#include <stdio.h>
#define ROWS 3
#define COLS 3

void func (int (*)[]);
int change[ROWS][COLS];
int main (void)
{
	int arr[ROWS][COLS];
	register int r, c;
	printf ("Enter %d*%d array:\n", ROWS, COLS);	
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			scanf ("%d", &arr[r][c]);
	printf ("转置前:\n");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf ("%d ", arr[r][c]);
		putchar('\n');
	}
	
	func (arr);
	printf ("转置后:\n");
	for (r = 0; r < ROWS; r++)
	{
		for (c = 0; c < COLS; c++)
			printf ("%d ", change[r][c]);
		putchar('\n');
	}
	
	return 0;
}

void func (int (* arr)[COLS])
{
	register int r, c;
	int temp;
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			change[c][r] = arr[r][c];
}
