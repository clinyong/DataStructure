/*插入排序*/

/*L为要排序的数组， n为数组长度*/
void insert(int *L, int n)
{
    int i, j;
    int temp;

    for(i = 1; i < n; i++) {
        if(L[i] < L[i-1]) {
            temp = L[i];
            /*如果L[j] > temp这个条件生效，表明此时j前面的数都比temp值要小，跳出循环，将temp插到L[j + 1]*/
            for(j = i - 1; j >= 0 && L[j] > temp; j--) {
                L[j+1] = L[j];
            }

            /*循环之后的j + 1，就是temp要插入的位置*/
            L[j + 1] = temp;
        }
    }
}
