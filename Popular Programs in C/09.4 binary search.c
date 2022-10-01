// WAP to implement binary search

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
int binarySearch(int *, int, int, int);

int main()
{
    int s, *a = input(&s), e, index;
    printf("Enter element to search: ");
    scanf("%d", &e);
    index = binarySearch(a, e, 0, s);
    if (index == -1)
        printf("%d not found in the array", e);
    else
        printf("%d found at index %d of the array", e, index);
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

int binarySearch(int *arr, int x, int low, int high)
{
    if (low > high)
        return -1;
    else
    {
        int mid = (low + high) / 2;
        if (x == arr[mid])
            return mid;
        else if (x > arr[mid])
            return binarySearch(arr, x, mid + 1, high);
        else
            return binarySearch(arr, x, low, mid - 1);
    }
}