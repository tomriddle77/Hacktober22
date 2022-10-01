// Find the non-diagonal elements of a matrix

#include <stdio.h>
#include <stdlib.h>

int **input(int *r, int *c);
void nonDiagonal(int **mat, int m, int n);

int main()
{
    int m, n, **mat = input(&m, &n);
    nonDiagonal(mat, m, n);
    return 0;
}

int **input(int *r, int *c)
{
    int i, j;
    printf("Enter the size of matrix as 'row column': ");
    scanf("%d %d", r, c);
    int **m = (int **)malloc((*r) * sizeof(int *));
    printf("Enter the matrix:\n");
    for (i = 0; i < *r; i++)
    {
        m[i] = (int *)malloc((*c) * sizeof(int));
        for (j = 0; j < *c; j++)
            scanf("%d", &m[i][j]);
    }
    return m;
}

void nonDiagonal(int **mat, int m, int n)
{
    int i, j;
    printf("Non-diagonal elements : ");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i != j)
                printf("%d ", mat[i][j]);
        }
    }
}
