/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2016年04月12日 星期二 23时24分29秒
 ************************************************************************/

#include<stdio.h>
int N;
int sum(int r, int j, int D[][N]) {
    if (r == N-1) {
        return D[r][j];
    } 
    int sum1 = sum(r+1, j, D);
    int sum2 = sum(r+1, j+1, D);
    if (sum1 > sum2)
        return sum1+D[r][j];
    else 
        return sum2+D[r][j];
}

int main(void) {
    printf("输入三角形的行数： ");
    scanf("%d", &N);
    int i, j, D[N][N];
    for (i = 0; i < N; i++)
        for (j = 0; j <= i; j++)
            scanf("%d", &D[i][j]);
    printf("自顶至底最佳路径长度： %d\n", sum(0, 0, D));
}
