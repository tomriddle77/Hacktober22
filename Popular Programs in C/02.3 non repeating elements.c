// Print all non-repeating elements in an array

#include <stdio.h>
#include <stdlib.h>

int *input(int *size);
void printNonRepeating(int *arr, int size);

typedef struct uniqueData
{
    int num;
    int inUnique;
} Unique;

int main()
{
    int s, *a = input(&s);
    printNonRepeating(a, s);
    return 0;
}

int *input(int *size)
{
    printf("Input array size: ");
    scanf("%d", size);
    int *array = (int *)malloc(sizeof(int) * (*size)), i;
    printf("Enter array elements: ");
    for (i = 0; i < *size; i++)
    {
        scanf("%d", &array[i]);
    }
    return array;
}

void printNonRepeating(int *arr, int size)
{
    Unique visited[size];
    int visitedSize = 0, i, j, unique;
    for (i = 0; i < size; i++)
    {
        unique = 1;
        for (j = 0; j < visitedSize; j++)
        {
            if (visited[j].num == arr[i])
            {
                visited[j].inUnique = 0;
                unique = 0;
                break;
            }
        }
        if (unique)
        {
            visited[visitedSize].num = arr[i];
            visited[visitedSize].inUnique = 1;
            visitedSize++;
        }
    }
    printf("Non-repeating elements: ");
    for (i = 0; i < visitedSize; i++)
    {
        if (visited[i].inUnique)
            printf("%d ", visited[i].num);
    }
}
