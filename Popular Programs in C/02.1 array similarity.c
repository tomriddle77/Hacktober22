// Check the similarity of two arrays and the extent of their dissimilarity

#include <stdio.h>
#include <stdlib.h>

int *input(int *size);
void compare(int *a1, int *a2, int s1, int s2, int *common, int *diff);

int main()
{
    int s1, s2, *a1 = input(&s1), *a2 = input(&s2), common, diff;
    compare(a1, a2, s1, s2, &common, &diff);
    printf("The arrays are similar by %d elements and dissimilar by %d elements", common, diff);
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

void compare(int *a1, int *a2, int s1, int s2, int *common, int *diff)
{
    int i, upto = (s1 >= s2) ? s2 : s1;
    *diff = (s1 >= s2) ? (s1 - s2) : (s2 - s1);
    *common = 0;
    for (i = 0; i < upto; i++)
    {
        if (a1[i] != a2[i])
            (*diff)++;
        else
            (*common)++;
    }
}
