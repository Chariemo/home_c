#include <stdio.h>
int partition(int *arr, int p, int n);
void sort(int *arr, int p, int n);

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    printf("\n");
    sort(arr, 0, n-1);
    for (i = 0; i < n; i++) {
        printf ("%d ", arr[i]);
    }
    printf ("\n");
    return 0;
}

int partition(int *arr, int p, int n) {
    int i, j, temp;
    int x = arr[n];
    i = p - 1;
    for (j = p; j < n; j++)
        if (arr[j] <= x) {
            i++;
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    temp = arr[i+1];
    arr[i+1] = arr[n];
    arr[n] = temp;
    return i+1;
}

void sort(int *arr, int p, int n) {
    int q;
    if (p < n) {
        q = partition(arr, p, n);
        sort(arr, p, q-1);
        sort(arr, q+1, n);
    }
}
