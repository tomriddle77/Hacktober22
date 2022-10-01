// WAP to implement bubble sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
void bubbleSort(int *, int);
void display(int *, int, char *);

int main()
{
    int s, *a = input(&s);
    display(a, s, "Before sorting: ");
    bubbleSort(a, s);
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

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size; i++)
        for (int j = 1; j < size; j++)
            if (array[j - 1] > array[j])
            {
                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
}

/*
Input array size: 5
Enter array elements: 4 2 5 1 3

Before sorting: 4 2 5 1 3
After  sorting: 1 2 3 4 5
*/