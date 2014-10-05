/*希尔排序*/

void shell(int *L, int n)
{
    int i, j, k;
    int temp;
    int gap; //步长

    for(gap = n/2; gap > 0; gap /= 2) {
        for(i = gap; i < n; i++) {
            if(L[i] < L[i - gap]) {
                temp = L[i];
                for(j = i - gap; j >= 0 &&  L[j] > temp; j -= gap) {
                    L[j + gap] = L[j];
                }
                L[j + gap] = temp;
            }
        }
    }
}
