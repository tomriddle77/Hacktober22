// WAP to implement merge sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
void mergeSort(int[], int, int);
void display(int *, int, char *);

int main()
{
    int s, *a = input(&s);
    display(a, s, "Before sorting: ");
    mergeSort(a, 0, s - 1);
    display(a, s, "After  sorting: ");
    return 0;
}

int *input(int *s)
{
    printf("Input array size: ");
    scanf("%d", s);
    int *a = (int *)malloc(sizeof(int) * (*s)), i;
    printf("Enter array elements: ");
    for (i = 0; i < *s; i++)
        scanf("%d", &a[i]);
    return a;
}

void display(int *a, int s, char *text)
{
    printf("\n%s", text);
    for (int i = 0; i < s; i++)
        printf("%d ", a[i]);
}

void mergeSort(int array[], int low, int high)
{
    if (low >= high)
        return;
    // int mid = low + (high - low) / 2;
    int mid = (high + low) / 2;
    mergeSort(array, low, mid);
    mergeSort(array, mid + 1, high);

    int ls = mid - low + 1, rs = high - mid, left[ls], right[rs];
    for (int i = 0; i < ls; i++)
        left[i] = array[low + i];
    for (int i = 0; i < rs; i++)
        right[i] = array[mid + i + 1];

    int li = 0, ri = 0, ai = low;
    while (li < ls && ri < rs)
    {
        if (left[li] <= right[ri])
        {
            array[ai] = left[li];
            li++;
        }
        else
        {
            array[ai] = right[ri];
            ri++;
        }
        ai++;
    }

    while (li < ls)
    {
        array[ai] = left[li];
        li++;
        ai++;
    }

    while (ri < rs)
    {
        array[ai] = right[ri];
        ri++;
        ai++;
    }
}

/*
Input array size: 5
Enter array elements: 4 2 5 1 3

Before sorting: 4 2 5 1 3
After  sorting: 1 2 3 4 5
*/