#include <stdio.h>
int size = 0;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

void heapify(int a[], int size, int i)
{
    if (size == 1)
    {
        printf("Heap has single element.");
    }
    else
    {
        int lerg = i;
        int lc = 2 * i + 1;
        int rc = 2 * i + 2;
        if (lc < size && a[lc] > a[lerg])
        {
            lerg = lc;
        }
        if (rc < size && a[rc] > a[lerg])
        {
            lerg = rc;
        }
        if (lerg != i)
        {
            swap(&a[i], &a[lerg]);
            heapify(a, size, lerg);
        }
    }
}

void insert(int a[], int newNum)
{
    if (size == 0)
    {
        a[0] = newNum;
        size += 1;
    }
    else
    {
        a[size] = newNum;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(a, size, i);
        }
    }
}

void max_printArr(int a[], int size)
{
    for (int i = 0; i < size; ++i)
        printf("%d ", a[i]);
    printf("\n");
}

void min_printArr(int a[], int size)
{
    for (int i = size - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");
}

int main()
{
    int a[10];
    insert(a, 6);
    insert(a, 7);
    insert(a, 8);
    insert(a, 4);
    insert(a, 2);
    
    printf("Max-Heap a: ");
    max_printArr(a, size);

    printf("Min-Heap a: ");
    min_printArr(a, size);

    return 0;
}