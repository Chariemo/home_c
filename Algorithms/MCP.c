#include<stdio.h>
#define M 50

typedef struct {
    int a[M][M];//图G的邻接矩阵
    int v;//顶点数
    int x[M];
    int bestx[M];
    int cnum;
    int bestn;
}MCP;

void Create(MCP *G) {
    int i, j;
    printf("边数: ");
    scanf("%d", &(G->v));
    printf("各边: ");
    for (i = 1; i <= G->v; i++)
        for (j = 1; j <= G->v; j++)
            scanf("%d", &(G->a[i][j]));
    for (i = 1; i <= G->v; i++) {
        G->bestx[i] = 0;
        G->x[i] = 0;
        G->bestn = 0;
        G->cnum = 0;
    }
}

void Backtrack(MCP *G, int i) {
    int j;
    if (i > G->v) {
        for (j = 1; j <= G->v; j++ ) {
            G->bestx[j] = G->x[j];
        }
        G->bestn = G->cnum;
        return;
    }
    int OK = 1;
    for (j = 1; j <= i; j++) {
        if (G->x[j] && G->a[i][j] == 0) {
            OK = 0;
            break;
        }
        if (OK) {
            G->x[i] = 1;
            G->cnum++;
            Backtrack(G, i+1);
            G->x[i] = 0;
            G->cnum--;
        }
        if (G->cnum + G->v - i > G->bestn) {
             G->x[i] = 0;
             Backtrack(G, i+1);
        }
    }
}

int main(void) {
    MCP G;
    Create(&G);
    Backtrack(&G, 1);
    printf("当前最大顶点数: %d\n", G.bestn);
    return 0;
}
