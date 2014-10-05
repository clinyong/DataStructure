/*冒泡排序*/
#include <stdio.h>

/*L为要排序的数组，n为数组长度*/
void bubble(int *L, int n)
{
    int i, j;
    int flag;
    int temp;

    flag = 1;
    while(flag) {
        flag = 0;
        for(j = 1; j < n; j++) {
            if(L[j-1] > L[j]) {
                temp = L[j - 1];
                L[j - 1] = L[j];
                L[j] = temp;
                flag = 1;
            }
        }

        n--;
    }
}
