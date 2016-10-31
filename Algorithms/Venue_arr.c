/*************************************************************************
	> File Name: venue_arr.c
	> Author:
	> Mail:
	> Created Time: 2016年04月27日 星期三 08时02分09秒
 ************************************************************************/

#include<stdio.h>
#include <stdbool.h>
typedef struct {
    int t;
    bool isSt;
}activity;

void sort(activity *ac, int n) {
    int i, j;
    activity  temp;

    for (i = 1; i < n*2; i++) {
        for (j = i+1; j < n*2; j++) {
            if (ac[i].t > ac[j].t) {
                temp = ac[i];
                ac[i] = ac[j];
                ac[j] = temp;
            }
        }
    }
}

int partitoin(activity *ac, int p, int n) {
    int x = ac[n].t;
    int i = p - 1;
    int j;
    activity temp;
    for (j = p; j < n; j++) {
        if (ac[j].t <= x) {
            i += 1;
            temp = ac[j];
            ac[j] = ac[i];
            ac[i] = temp;
        }
    }
    temp = ac[i+1];
    ac[i+1] = ac[n];
    ac[n] = temp;
    return i+1;
}
void sort_q(activity *ac,int p, int n) {
    int q;
    if (p < n) {
        q = partitoin(ac, p, n);
        sort_q(ac, p, q-1);
        sort_q(ac, q+1, n);
    }
}
int main(void) {
    int n, i, max_count;
    printf("输入活动个数: ");
    scanf("%d", &n);
    getchar();
    activity ac[n*2];
    printf("输入活动开始以及结束时间: ");
    for (i = 0; i < n*2; i++){
        scanf("%d", &ac[i].t);
        if (i % 2 == 0)
            ac[i].isSt = true;
        else
            ac[i].isSt = false;
    }
    sort_q(ac, 0, n*2-1);
    //sort(ac, n);
    for (i = 0; i < n*2; i++) {
        printf("%d ", ac[i].t);
    }
    printf("\n");
    int count[n*2];
    count[0] = 1;
    for (i = 1; i < n*2; i++) {
        if (ac[i].isSt)
            count[i] = count[i-1] + 1;
        else
            count[i] = count[i-1] - 1;
    }
    max_count = count[0];
    for (i = 1; i < n*2; i++)
        if (max_count <= count[i])
            max_count = count[i];
    printf("至少需会场数: %d\n", max_count);
    return 0;
}

