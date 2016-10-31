#include<stdio.h>
#include<stdlib.h>
typedef struct {
    int n;
    int *x;
    int *bestx;

    int *w;
    int c;
    int cw;
    int bestw;
    int r;
}Loading;
/*int bestw = 0;*/
Loading X;
void Backtrack(int i) {
    int j;
    if (i > X.n) {
        if (X.cw > X.bestw) {
            for (j = 1; j <= X.n; j++) {
                X.bestx[j] = X.x[j];
            }
            X.bestw = X.cw;
        }
        return;
    }
    X.r -= X.w[i];
    if (X.cw + X.w[i] <= X.c) {
         X.x[i] = 1;
         X.cw += X.w[i];
         Backtrack(i+1);
         X.cw -= X.w[i];
    }
    if (X.cw + X.r > X.bestw) {
         X.x[i] = 0;
         Backtrack(i+1);
    }
    X.r += X.w[i];
}

int main(void) {
    printf("集装箱数: ");
    scanf("%d", &X.n);
    X.w = (int *) malloc(sizeof(int) * X.n);
    printf("集装箱重量: ");
    int i;
    for (i = 1; i <= X.n; i++) {
        scanf("%d", &X.w[i]);
    }
    printf("船载重量: ");
    scanf("%d", &X.c);
    X.x = (int *) malloc(sizeof(int) * (X.n + 1));
    X.bestx = (int *) malloc(sizeof(int) * (X.n + 1));
    X.bestw = 0;
    X.cw = 0;
    X.r = 0;
    for (i = 1; i <= X.n; i++) {
         X.r += X.w[i];
    }
    Backtrack(1);

    printf("最优解重量: %d\n", X.bestw);
    return 0;
}

