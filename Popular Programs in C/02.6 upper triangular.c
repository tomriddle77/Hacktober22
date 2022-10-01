// Find the upper triangular elements of a matrix

#include <stdio.h>
#include <stdlib.h>

int **input(int *r, int *c);
void upperTriangular(int **mat, int m, int n);

int main()
{
    int m, n, **mat = input(&m, &n);
    upperTriangular(mat, m, n);
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

void upperTriangular(int **mat, int m, int n)
{
    int i, j;
    printf("Upper triangular elements :\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j >= i)
                printf("%-3d", mat[i][j]);
            else
                printf("   ");
        }
        printf("\n");
    }
}
