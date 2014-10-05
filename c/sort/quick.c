/*快速排序*/
#include <stdio.h>

void quickSort(int *L, int n)
{
    int i, j, x;

    if (n > 1) {
        x = L[0]; //先在第一个位置挖出一个坑
        i = 0; //从左边第一个元素开始
        j = n - 1; //从右边最后一个元素开始

        while (i < j) {
            /*从右到左找出第一个值小于x的数，将其填入到左边的坑*/
            while (i < j && L[j] >= x) {
                j--;
            }
            if (i < j) {
                L[i] = L[j];
                i++;
            }

            /*从左边找出第一个值大于x的数，将其填入右边的坑*/
            while (i < j && L[i] <= x) {
                i++;
            }
            if (i < j) {
                L[j] = L[i];
                j--;
            }
        }
        /*将最后一个坑用x填入*/
        L[i] = x;

        /*i+1为下标i之前的元素个数*/
        quickSort(L, i + 1);
        quickSort(L + i + 1, n - i - 1);
    }
}

int main()
{
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i;
    int len;

    len = 10;

    quickSort(arr, len);
    for(i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
