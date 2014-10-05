/*堆排序*/
#include <stdio.h>

#define leftChild(i) (2 * (i) + 1)

void printfArr(int *L, int n)
{
    int i;

    for(i = 0; i < n; i++) {
        printf("%d", L[i]);
    }

    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*s为数组中要排序元素的下标*/
void heapAdjust(int *L, int s, int n)
{
    int temp;
    int child;

    temp = L[s];

    /*先将孩子的下标初始化为左孩子*/
    child = leftChild(s);
    while(child < n) {
        /*如果左孩子比右孩子小，孩子的下标变成右孩子*/
        if(child != (n - 1) && L[child] < L[child + 1]) {
            child++;
        }

        /*如果要插入的值大于插入点的孩子，直接退出，该值就插在此插入点*/
        if(temp >= L[child]) {
            break;
        }

        L[s] = L[child];
        s = child;

        child = leftChild(child);
    }

    L[s] = temp;
}

/*堆排序，数组下表从0开始*/
void heap(int *L, int n)
{
    int i;
    int temp;

    /*将数组调整为大顶堆，i从有孩子的最后一个节点开始排序*/
    for(i = n / 2; i >= 0; i--) {
        heapAdjust(L, i, n);
    }


    for(i = n - 1; i > 0; i--) {
        /*将数组的第一个元素和未排序的最后一个交换，使得最大的元素排到最后*/
        swap(&L[0], &L[i]);

        /*将剩下的未排序元素重新组成大顶堆*/
        heapAdjust(L, 0, i);
    }
}
