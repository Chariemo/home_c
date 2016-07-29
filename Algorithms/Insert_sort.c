#include <stdio.h>

void insertsort(int *arr, int n) {
    int i, j;
    int key;
    for (j = 1; j <= n; j++) {
        i = j - 1;
        key = arr[j];
        while (i > -1 && arr[i] > key) {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int i;
    int arr[n];
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for (i = 0; i < n; i++) {
         printf("%d ", arr[i]);
    }
    printf("\n");
    insertsort(arr, n-1);
    for (i = 0; i < n; i++) {
         printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
