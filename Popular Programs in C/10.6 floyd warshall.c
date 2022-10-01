// WAP to implement Floyd Warshall algorithm

#include <stdio.h>
#include <stdlib.h>

int **input(int *);
void display(int **, int);
void floydWarshall(int **, int);

int main()
{
    int v, **g = input(&v);
    floydWarshall(g, v);
    display(g, v);
    return 0;
}

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

void display(int **g, int v)
{
    printf("\nAll pairs shortest path matrix:\n");
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
            printf("%-3d ", g[i][j]);
        printf("\n");
    }
}

void floydWarshall(int **g, int v)
{
    for (int k = 0; k < v; k++)
    {
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                int oldPath = g[i][j];
                int newPath = g[i][k] + g[k][j];
                if (oldPath == -1 && (g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = -1;
                else if (oldPath == -1)
                    g[i][j] = newPath;
                else if ((g[i][k] == -1 || g[k][j] == -1))
                    g[i][j] = oldPath;
                else
                    g[i][j] = (newPath < oldPath) ? newPath : oldPath;
            }
        }
    }
}

/*
Enter total vertices: 4
Enter the adjacency matrix (0 for i to i, -1 for infinity):
0 3 -1 7
8 0 2 -1
5 -1 0 1
2 -1 -1 0

All pairs shortest path matrix:
0   3   5   6
5   0   2   3
3   6   0   1
2   5   7   0
*/