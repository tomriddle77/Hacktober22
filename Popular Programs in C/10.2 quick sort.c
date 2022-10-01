// WAP to implement quick sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
void swap(int *, int *);
void quickSort(int[], int, int);
void display(int *, int, char *);

int main()
{
    int s, *a = input(&s);
    display(a, s, "Before sorting: ");
    quickSort(a, 0, s - 1);
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

void swap(int *e1, int *e2)
{
    int temp = *e1;
    *e1 = *e2;
    *e2 = temp;
}

void quickSort(int array[], int low, int high)
{
    if (low >= high)
        return;
    int i = low, j = high, pivot = array[low];
    while (j > i)
    {
        while ((pivot >= array[i]) && i <= high)
            i++;
        while ((pivot < array[j]) && j >= low)
            j--;
        if (j > i)
            swap(&array[i], &array[j]);
    }
    swap(&array[j], &array[low]);
    quickSort(array, low, j - 1);
    quickSort(array, j + 1, high);
}

/*
Input array size: 5
Enter array elements: 4 2 5 1 3

Before sorting: 4 2 5 1 3
After  sorting: 1 2 3 4 5
*/