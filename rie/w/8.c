/*找出数组的鞍点*/
#include<stdio.h>
#define ROWS 4
#define COLS 4
int main (void)
{
    int list[ROWS][COLS];
    int i, j, x, n, l, flog;
    
    printf("please enter %d * %d array:",ROWS,COLS);
    for (i = 0; i < ROWS; i++)
    {
	for (j = 0; j < COLS; j++)
	    scanf("%d",&list[i][j]);
    }
    
    for (i = 0; i < ROWS; i++)
    {
	x = list[i][0];
	l = 0;
	for (j = 1; j < COLS; j++)
	    if (list[i][j] > x)
	    {
		x = list[i][j];
		l = j;
	    }
	n = list[i][l];
        flog = 1;
	for (j = 0; j < ROWS; j++)
	{
	    if (list[j][l] < n)
		flog = 0;
	}
	if (flog == 1)
	    printf("(%d,%d) = %d 为鞍点.\n",i+1,l+1,list[i][l]);
    }
	printf("If none print means 没有鞍点\n");
	return 0;
}
