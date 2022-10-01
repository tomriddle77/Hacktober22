#include <stdio.h>

int *create(int *size);
int linearSearch(int *array, int size, int element);
int binarySearch(int *array, int size, int element);

void main()
{
    int size, *array = create(&size), element;
    printf("Enter element to search: ");
    scanf("%d", &element);
    printf("Linear search index: %d\n", linearSearch(array, size, element));
    printf("Binary search index: %d\n", binarySearch(array, size, element));
}

int binarySearch(int *array, int size, int element)
{
    int l = 0, u = size - 1, mid;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (element == array[mid])
            return mid;
        else if (element < array[mid])
            u = mid - 1;
        else if (element > array[mid])
            l = mid + 1;
    }
    return -1;
}

int linearSearch(int *array, int size, int element)
{
    for (int i = 0; i < size; i++)
        if (array[i] == element)
            return i;
    return -1;
}

int *create(int *size)
{
    printf("Total elements: ");
    scanf("%d", size);
    int *array = (int *)malloc((*size) * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
    return array;
}