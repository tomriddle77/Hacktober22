// WAP to implement power of adjacency matrix algorithm

#include <stdio.h>
#include <stdlib.h>

int **input(int *v)
{
    printf("Enter total vertices: ");
    scanf("%d", v);
    printf("Enter the adjacency matrix (0 for i to i, -1 for infinity):\n");
    int **matrix = (int **)malloc((*v) * sizeof(int *));
    for (int i = 0; i < *v; i++)
    {
        matrix[i] = (int *)malloc((*v) * sizeof(int));
        for (int j = 0; j < *v; j++)
            scanf("%d", &matrix[i][j]);
    }
    return matrix;
}

void display(int **g, int v, char *text)
{
    printf("%s", text);
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%-3d ", g[i][j]);
        printf("\n");
    }
}

int **multiply(int **m1, int **m2, int v)
{
    int **matrix = (int **)malloc((v) * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        matrix[i] = (int *)malloc((v) * sizeof(int));
        for (int j = 0; j < v; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < v; k++)
                matrix[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return matrix;
}

int **add(int **m1, int **m2, int v)
{
    int **matrix = (int **)malloc((v) * sizeof(int *));
    for (int i = 0; i < v; i++)
    {
        matrix[i] = (int *)malloc((v) * sizeof(int));
        for (int j = 0; j < v; j++)
            matrix[i][j] = m1[i][j] + m2[i][j];
    }
    return matrix;
}

int **powerOfAdjMat(int **g, int v)
{
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
        {
            if (g[i][j] == -1)
                g[i][j] = 0;
            else if (g[i][j] != 0)
                g[i][j] = 1;
        }

    int ***m = (int ***)malloc((v) * sizeof(int **));
    m[0] = g;
    for (int i = 1; i < v; i++)
    {
        m[i] = multiply(m[i - 1], g, v);
        m[0] = add(m[i], m[0], v);
    }

    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            if (m[0][i][j] != 0)
                m[0][i][j] = 1;
    return m[0];
}

int main()
{
    int v, **g = input(&v), **pOfAdjMat;
    pOfAdjMat = powerOfAdjMat(g, v);
    display(pOfAdjMat, v, "\nReachability matrix using power of adjacency matrix algorithm:\n");
    return 0;
}