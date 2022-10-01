// WAP in C to perform matrix addition

#include <stdio.h>
#include <stdlib.h>

int **input(int r, int c);
int **add(int **m1, int **m2, int r, int c);
void display(int **m, int r, int c);

int main()
{
    int r,c;

    printf("Enter the size of matrix as 'row column': ");
    scanf("%d %d",&r,&c);

    int **m1=input(r,c),**m2=input(r,c),**m=add(m1,m2,r,c);

    printf("\nSUM\n");
    display(m,r,c);

    return 0;
}

int **input(int r, int c)
{
    int i,j;
    int **m=(int **)malloc(r*sizeof(int *));
    printf("Enter the matrix:\n");
    for(i=0; i<r; i++)
    {
        m[i]=(int *)malloc(c*sizeof(int));
        for(j=0; j<c; j++)
            scanf("%d",&m[i][j]);
    }
    return m;
}

int **add(int **m1, int **m2, int r, int c)
{
    int i,j;
    int **sum=(int **)malloc(r*sizeof(int *));
    for(i=0; i<r; i++)
    {
        sum[i]=(int *)malloc(c*sizeof(int));
        for(j=0; j<c; j++)
            sum[i][j]=m1[i][j]+m2[i][j];
    }
    return sum;
}

void display(int **m, int r, int c)
{
    int i,j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
            printf("%-3d",m[i][j]);
        printf("\n");
    }
}
