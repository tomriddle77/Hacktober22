#include <stdio.h>
#include <stdlib.h>

int **inputSMatrix(int *count);
int **inputMatrix(int *row, int *column);
void displayMatrix(int **matrix, int row, int column);
int **toSparse(int **matrix, int row, int column, int *count);
int **fromSparse(int **sparseMat, int *row, int *column, int count);

void main()
{
    int choice, row, col, count, **matrix, **sMatrix;
loop:
    printf("1: Normal to sparse matrix\n2: Sparse to normal matrix\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        matrix = inputMatrix(&row, &col);
        printf("\n");
        sMatrix = toSparse(matrix, row, col, &count);
        printf("Equivalent sparse matrix:\n");
        displayMatrix(sMatrix, 3, count);
        printf("\n");
        for (int i = 0; i < 3; i++)
            free(sMatrix[i]);
        free(sMatrix);
        for (int i = 0; i < row; i++)
            free(matrix[i]);
        free(matrix);
        goto loop;
    case 2:
        sMatrix = inputSMatrix(&count);
        printf("\n");
        matrix = fromSparse(sMatrix, &row, &col, count);
        printf("Equivalent normal matrix:\n");
        displayMatrix(matrix, row, col);
        printf("\n");
        for (int i = 0; i < 3; i++)
            free(sMatrix[i]);
        free(sMatrix);
        for (int i = 0; i < row; i++)
            free(matrix[i]);
        free(matrix);
        goto loop;
    }
}

int **inputMatrix(int *row, int *column)
{
    printf("Enter size of matrix as: row column: ");
    scanf("%d %d", row, column);
    printf("Enter a %dx%d matrix:\n", *row, *column);
    int **matrix = (int **)malloc((*row) * sizeof(int *));
    for (int i = 0; i < *row; i++)
    {
        matrix[i] = (int *)malloc((*column) * sizeof(int));
        for (int j = 0; j < *column; j++)
            scanf("%d", &matrix[i][j]);
    }
    return matrix;
}

int **inputSMatrix(int *count)
{
    printf("Enter count of sparse matrix as: ");
    scanf("%d", count);
    printf("Enter a 3x%d sparse matrix:\n", *count);
    int **matrix = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        matrix[i] = (int *)malloc((*count) * sizeof(int));
        for (int j = 0; j < *count; j++)
            scanf("%d", &matrix[i][j]);
    }
    return matrix;
}

void displayMatrix(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%-3d ", matrix[i][j]);
        printf("\n");
    }
}

int **fromSparse(int **sparseMat, int *row, int *column, int count)
{
    *row = sparseMat[0][0], *column = sparseMat[1][0];
    for (int i = 1; i < count; i++)
    {
        if (sparseMat[0][i] > *row)
            *row = sparseMat[0][i];
        if (sparseMat[1][i] > *column)
            *column = sparseMat[1][i];
    }
    (*row)++;
    (*column)++;
    int **matrix = (int **)malloc((*row) * sizeof(int *));
    for (int i = 0; i < *row; i++)
    {
        matrix[i] = (int *)malloc((*column) * sizeof(int));
        for (int j = 0; j < *column; j++)
            matrix[i][j] = 0;
    }
    for (int i = 0; i < count; i++)
        matrix[sparseMat[0][i]][sparseMat[1][i]] = sparseMat[2][i];
    return matrix;
}

int **toSparse(int **matrix, int row, int column, int *count)
{
    *count = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] != 0)
                (*count)++;
    int **sparseMat = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
        sparseMat[i] = (int *)malloc((*count) * sizeof(int));
    *count = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            if (matrix[i][j] != 0)
            {
                sparseMat[0][*count] = i;
                sparseMat[1][*count] = j;
                sparseMat[2][*count] = matrix[i][j];
                (*count)++;
            }
    return sparseMat;
}