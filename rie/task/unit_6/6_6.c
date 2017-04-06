/*输出4*4阶矩阵的最大值　最小值及其坐标*/

#include <stdio.h>
#define ROWS 4
#define COLS 4

int max, min, r_max, c_max, r_min, c_min;

void func (int (* arr) []);

int main (void)
{
	int arr[ROWS][COLS];
	register int r, c;
	printf ("Enter %d*%d array: \n", ROWS, COLS);
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
			scanf ("%d", &arr[r][c]);
	func (arr);
	
	printf ("矩阵中最大值为%d, 其坐标(%d,%d); \n最小值为%d, 其坐标(%d,%d).\n",
		max, r_max+1, c_max+1, min, r_min+1, c_min+1);
	return 0;
}

void func (int arr[][COLS])
{
	register int r, c;
	max = arr[0][0]; r_max = 0; c_min = 0;
	min = arr[0][0]; r_min = 0; c_min = 0;
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
		{
			if (max < arr[r][c])
			{
				max = arr[r][c];
				r_max = r;
				c_max = c;
			}
			if (min > arr[r][c])
			{
				min = arr[r][c];
				r_min = r;
				c_min = c;
			}
		}
}
	
