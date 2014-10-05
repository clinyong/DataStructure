/*选择排序，时间复杂度为O[n^2]*/

/*L为要排序的数组，n为数组长度*/
void select(int *L, int n)
{
    int i, j, min;
    int temp;

    for(i = 1; i < n; i++) {
        min = i;

        for(j = i+1; j < n; j++) {
            if(L[min] > L[j]) {
                min = j;
            }
        }

        if(min != i) {
            temp = L[min];
            L[min] = L[i];
            L[i] = temp;
        }
    }
}
