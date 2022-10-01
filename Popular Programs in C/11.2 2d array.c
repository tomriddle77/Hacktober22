#include <stdio.h>
#include <stdlib.h>

int **input(int *row, int *column);
void display(int **matrix, int row, int column);
int **add(int **m1, int **m2, int row, int column);
int **subtract(int **m1, int **m2, int row, int column);
int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2);
int **transpose(int **m, int row, int column);

void main()
{
    int r1, c1, **m1 = input(&r1, &c1);
    int r2, c2, **m2 = input(&r2, &c2);
    int choice;

loop:
    printf("1: Add\n2: Subtract\n3: Multiply\n4: Transpose\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("SUM\n");
        int **mSum = add(m1, m2, r1, c1);
        display(mSum, r1, c1);
        printf("\n");
        goto loop;

    case 2:
        printf("DIFFERENCE\n");
        int **mDif = subtract(m1, m2, r1, c1);
        display(mDif, r1, c1);
        printf("\n");
        goto loop;

    case 3:
        printf("PRODUCT\n");
        int **mPro = multiply(m1, m2, r1, c1, r2, c2);
        display(mPro, r1, c2);
        printf("\n");
        goto loop;

    case 4:
        printf("TRANSPOSE of M1\n");
        int **mTra1 = transpose(m1, r1, c1);
        display(mTra1, r1, c1);
        printf("\n");
        printf("TRANSPOSE of M2\n");
        int **mTra2 = transpose(m2, r2, c2);
        display(mTra2, r2, c2);
        printf("\n");
        goto loop;

    default:
        goto loop;
    }
}

int **input(int *row, int *column)
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
    system("cls");
    return matrix;
}

void display(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            printf("%02d ", matrix[i][j]);
        printf("\n");
    }
}

int **add(int **m1, int **m2, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        for (int j = 0; j < column; j++)
            matrix[i][j] = m1[i][j] + m2[i][j];
    }
    return matrix;
}

int **subtract(int **m1, int **m2, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        for (int j = 0; j < column; j++)
            matrix[i][j] = m1[i][j] - m2[i][j];
    }
    return matrix;
}

int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2)
{
    if (c1 != r2)
        return;
    int **matrix = (int **)malloc((r1) * sizeof(int *));
    for (int i = 0; i < r1; i++)
    {
        matrix[i] = (int *)malloc((c2) * sizeof(int));
        for (int j = 0; j < c2; j++)
        {
            matrix[i][j] = 0;
            for (int k = 0; k < c1; k++)
                matrix[i][j] += m1[i][k] * m2[k][j];
        }
    }
    return matrix;
}

int **transpose(int **m, int row, int column)
{
    int **matrix = (int **)malloc((row) * sizeof(int *));
    for (int i = 0; i < row; i++)
    {
        matrix[i] = (int *)malloc((column) * sizeof(int));
        for (int j = 0; j < column; j++)
            matrix[i][j] = m[j][i];
    }
    return matrix;
}