// WAP to implement linear search

#include <stdio.h>
#include <stdlib.h>

int *input(int *);
int linearSearch(int *, int, int);

int main()
{
    int s, *a = input(&s), e, index;
    printf("Enter element to search: ");
    scanf("%d", &e);
    index = linearSearch(a, s, e);
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

int linearSearch(int *a, int s, int e)
{
    for (int i = 0; i < s; i++)
        if (a[i] == e)
            return i;
    return -1;
}