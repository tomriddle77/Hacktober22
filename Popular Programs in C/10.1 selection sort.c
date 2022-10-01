// WAP to implement selection sort

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
void selectionSort(int *, int);
void display(int *, int, char *);

int main()
{
    int s, *a = input(&s);
    display(a, s, "Before sorting: ");
    selectionSort(a, s);
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

void selectionSort(int *array, int size)
{
    int smallest, id, temp;
    for (int i = 0; i < size; i++)
    {
        smallest = array[i];
        id = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < smallest)
            {
                smallest = array[j];
                id = j;
            }
        }
        temp = array[i];
        array[i] = array[id];
        array[id] = temp;
    }
}

/*
Input array size: 5
Enter array elements: 4 2 5 1 3

Before sorting: 4 2 5 1 3
After  sorting: 1 2 3 4 5
*/