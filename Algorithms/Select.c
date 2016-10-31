#include<stdio.h>

int Partition (int *a, int p, int r) {
    int x = a[r];
    int i = p - 1;
    int j, temp;
    for (j = p; j < r; j++) {
        if (a[j] <= x) {
            i++;
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    }
    temp = a[r];
    a[r] = a[i+1];
    a[i+1] = temp;
    return i+1;
}

int Selelct(int *a, int p, int r, int k) {
    if (p == r) {
        return a[p];
    }
    int i = Partition(a, p, r);
    int j = i - p + 1;
    if (j < k) {
        return Selelct(a, i+1, r, k-j);
    }
    else {
      return Selelct(a, p, i, k);
    }
}

int main(void) {
     int n;
     printf("元素个数: ");
     scanf("%d", &n);
     int a[n+1];
     printf("输入元素: ");
     int i;
     for (i = 1; i <= n; i++) {
          scanf("%d", &a[i]);
     }
     printf("需要数的排序号: ");
     int k;
     scanf("%d", &k);

    printf("所求数为: %d\n", Selelct(a, 1, n, k));
    return 0;
}
