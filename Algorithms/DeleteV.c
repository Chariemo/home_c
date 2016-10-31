#include<stdio.h>
#include<string.h>

int main(void) {
    char arr[20];
    int k;
    printf("输入正整数: ");
    scanf("%s", arr);
    printf("输入k: ");
    scanf("%d", &k);
    int len = strlen(arr);
    while (k--) {
        int i = 0, j;
        while (i < len - 1 && arr[i] <= arr[i+1])
                i++;
        if (i == len -1) {
            //字符串递增 删除后k位
            len--;
            while (k--) {
                len--;
            }
            break;
        }
        else {
            //字符串非递增 删除数大的位数
            for (j = i; j < len -1; j++)
                    arr[j] = arr[j+1];
            len--;
        }
    }
    int l;

    for (l = 0 ; l < len; l++)
            printf("%c", arr[l]);
    printf("\n");
    return 0;
}
