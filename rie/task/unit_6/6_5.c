/* 调用函数将5*5阶矩阵最大元素放中心, 四个角分别为四个最小值(从左到右 从上到下递增 */

#include <stdio.h>
#define ROWS 5
#define COLS 5
int count = 0;
void func (int (*arr)[], int []);
int main (void)
{
	int arr[ROWS][COLS], sort[ROWS*COLS];
	register int r, c;	
	int change, temp;
	printf ("Enter %d*%d array:", ROWS, COLS);
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
		{
			scanf ("%d", &arr[r][c]);
			sort[count++] = arr[r][c];
		}	
	
	for (r = 0; r < count; r++)
	{
		change = 1;
		for (c = 0; c < count-r-1 && change; c++)
			if (sort[c] > sort[c+1])
			{
				temp = sort[c];
				sort[c] = sort[c+1];
				sort[c+1] = temp;
				change = 1;
			}
	}
	func (arr,sort);
	for (r = 0; r < ROWS; r++)
	{	
		for (c = 0; c < COLS; c++)
			printf ("%d ", arr[r][c]);
		putchar ('\n');
	}
	
	return 0;
}

void func (int (*arr)[COLS], int sort[count])
{
	register int r, c;
	int r_max, c_max, r_min1, c_min1, r_min2, c_min2, r_min3, c_min3;
	int r_min4, c_min4, temp;
	for (r = 0; r < ROWS; r++)
		for (c = 0; c < COLS; c++)
		{
			if (arr[r][c] == sort[count-1])
			{
				r_max = r;
				c_max = c;
			}
			if (arr[r][c] == sort[0])
			{
				r_min1 = r;
				c_min1 = c;
			}
			if (arr[r][c] == sort[1])
			{
				r_min2 = r;
				c_min2 = c;
			}
			if (arr[r][c] == sort[2])
			{
				r_min3 = r;
				c_min3 = c;
			}
			if (arr[r][c] == sort[3])
			{
				r_min4 = r;
				c_min4 = c;
			}
		}
	temp = arr[r_max][c_max];
	arr[r_max][c_max] = arr[2][2];
	arr[2][2] = temp;
	
	temp = arr[r_min1][c_min1];
	arr[r_min1][c_min1] = arr[0][0];
	arr[0][0] = temp;

	temp = arr[r_min2][c_min2];
	arr[r_min2][c_min2] = arr[4][0];
	arr[4][0] = temp;
	
	temp = arr[r_min3][c_min3];
	arr[r_min1][c_min1] = arr[0][4];
	arr[0][4] = temp;

	temp = arr[r_min4][c_min4];
	arr[r_min4][c_min4] = arr[4][4];
	arr[4][4] = temp;
}
