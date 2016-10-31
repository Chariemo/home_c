/*************************************************************************
	> File Name: cut_rod.c
	> Author:
	> Mail:
	> Created Time: 2016年04月26日 星期二 16时21分45秒
 ************************************************************************/

#include<stdio.h>
#define MIN -1
#define N 10
int cut_rod(int *p, int n) {
    if (n == 0) {
        return 0;
    }
    int q = MIN;
    int i;
    for (i = 1; i <= n; i++) {
        q = (q > p[i] + cut_rod(p, n-i))? q : p[i] + cut_rod(p, n-i);
    }
    return q;
}

//带备忘录自顶向下cut_rod
int memoized_cut_rod_aux(int *p, int n, int *r) {
    int i, q;
    if (r[n] >= 0) {
        return r[n];
    }
    if (n == 0) {
        q = 0;
    }
    else {
        q = MIN;
        for (i = 1; i <= n; i++) {
            q = (q > p[i] + memoized_cut_rod_aux(p, n-i, r)) ? q : p[i] + memoized_cut_rod_aux(p, n-i, r);
        }
    }
    r[n] = q;
    return q;
}
int memoized_cut_rod(int *p, int n) {
    int i;
    int r[N+1];
    for (i = 1; i <= N; i++) {
        r[i] = MIN;
    }
    return memoized_cut_rod_aux(p, n, r);
}


//自底向上
int bottom_up_cut_rod(int *p, int n) {
    int r[N+1];
    int i, j, q;
    r[1] = 0;
    for (j = 1; j <= n; j++) {
        q = MIN;
        for (i = 1; i <= j; i++) {
            q = (q > p[i] + r[j-i]) ? q : p[i] + r[j-i];
        }
        r[j] = q;
    }
    return r[n];
}



int main(void) {
    int p[N+1];
    int i;
    for (i = 1; i <= N; i++) {
        scanf("%d", &p[i]);
    }
    printf ("max_values: %d\n", bottom_up_cut_rod(p, N));
    return 0;
}
