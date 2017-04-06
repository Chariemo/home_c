/*找出6＊6矩阵每列绝对值最大的元素，并与同列对角线元素交换*/
#include<stdio.h>
#include<math.h>
#define ROWS 6
#define COLS 6
int main (void)
{
    float ar[ROWS][COLS], max, c;
    int i, j, n;
    
    printf("Please enter array[%d][%d]:\n",ROWS, COLS);
    for (i = 0; i < ROWS; i++)
	for (j = 0; j < COLS; j++)
	    scanf("%f",&ar[i][j]);

    for (i = 0; i < ROWS; i++)
    {
	for (j = 0; j < COLS; j++)
	    printf("%3.0f ",ar[i][j]);
	printf("\n");
    }

    for (j = 0; j < COLS; j++)
    {
	max = abs(ar[0][j]);
	n = 0;
	for (i = 1; i < ROWS; i++)
	    if (max < abs(ar[i][j])){
		max = abs(ar[i][j]);
		n = i;}
	c = ar[n][n];
	ar[n][n] = ar[n][j];
	ar[n][j] = c;
    }

    printf("Changed:\n");
    for (i = 0; i < ROWS; i++){
	for (j = 0; j < COLS; j++)
	    printf("%3.0f ",ar[i][j]);
	printf("\n");}
    return 0;
}
    
	
