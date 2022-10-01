// WAP to implement insertion sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
void insertionSort(int *, int);
void display(int *, int, char *);

int main()
{
    int s, *a = input(&s), e;
    display(a, s, "Before sorting: ");
    insertionSort(a, s);
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

void insertionSort(int *arr, int s)
{
    int i, key, j;
    for (i = 1; i < s; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}