/*************************************************************************
	> File Name: juzhen.c
	> Author: 
	> Mail: 
	> Created Time: 2016年03月30日 星期三 08时52分49秒
 ************************************************************************/

#include<stdio.h>
#define MAX 32767
#define LEN 7
void MATRIX_CHAIN_ORDER(int *p, int m[][LEN], int s[][LEN])
{
    int i, j, k, l, n, q;
    n = LEN-1;
    for (i = 1; i <= n; i++)
    {
        m[i][j] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n-l+1; i++) 
        {
            j = i + l -1;
            m[i][j] = MAX;
            for (k = i; k <= j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}
 
 void PRINT_OPTIMAL_PARENS(int s[][LEN], int i, int j)
 {
     if (i == j) {
        printf("A%d", i);
     }
     else
     {
         printf("(");
         PRINT_OPTIMAL_PARENS(s, i, s[i][j]);
         PRINT_OPTIMAL_PARENS(s, s[i][j]+1, j);
         printf (")");
     }
 }

 int main(void) 
 {
     int p[LEN] = {5, 10, 3, 12, 5, 50, 6};
     int m[LEN][LEN], s[LEN][LEN];
     MATRIX_CHAIN_ORDER(p, m, s);
     PRINT_OPTIMAL_PARENS(s, 1, LEN-1);
     return 0;
 }
