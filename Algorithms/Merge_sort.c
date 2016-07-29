#include <stdio.h>
#define M 1000
void MergeSort(int *arr, int p, int n) {
    if (n > p) {
        int q = (p+n) / 2;
        MergeSort(arr, p, q);
        MergeSort(arr, p+1, n);
        Merge(arr, p, q, n);
    }
}

void Merge(int *arr, int p, int q, int n) {
    int n1 = q - p + 1;
    int n2 = n - q;
    int L[n1+1], R[n2+1];
    int i, j = 0, k = 0;
    for (i = p; i <= n; i++) {
        if (i <= q) {
            L[j++] = arr[i];
        }
        else {
            R[k++] = arr[i];
        }
    }
    L[n1] = M;
    R[n2] = M;
    i = 0;
    j = 0;
    for (k = p; k <= n; k++) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
             arr[k] = R[j];
             j++;
        }
    }
}

int main(void) {
    int n;
    printf("N: ");
    scanf("%d", &n);
    int arr[n];
    printf("data: ");
    int i;
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    MergeSort(arr, 0, n-1);
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
