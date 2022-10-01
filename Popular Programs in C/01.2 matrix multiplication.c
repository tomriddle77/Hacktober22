// WAP in C to perform matrix multiplication

#include <stdio.h>
#include <stdlib.h>

int **input(int *r, int *c);
int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2);
void display(int **m, int r, int c);

int main()
{
    int r1,r2,c1,c2,**m1=input(&r1,&c1),**m2=input(&r2,&c2);

    if(c1!=r2)
    {
        printf("The matrices cannot be multiplied!");
        return 0;
    }

    int **m=multiply(m1,m2,r1,c1,r2,c2);

    printf("\nPRODUCT\n");
    display(m,r1,c2);

    return 0;
}

int **input(int *r, int *c)
{
    int i,j;
    printf("Enter the size of matrix as 'row column': ");
    scanf("%d %d",r,c);
    int **m=(int **)malloc((*r)*sizeof(int *));
    printf("Enter the matrix:\n");
    for(i=0; i<*r; i++)
    {
        m[i]=(int *)malloc((*c)*sizeof(int));
        for(j=0; j<*c; j++)
            scanf("%d",&m[i][j]);
    }
    return m;
}

int **multiply(int **m1, int **m2, int r1, int c1, int r2, int c2)
{
    int i,j,k;
    int **product=(int **)malloc(r1*sizeof(int *));
    for(i=0; i<r1; i++)
    {
        product[i]=(int *)malloc(c2*sizeof(int));
        for(j=0; j<c2; j++)
        {
            product[i][j]=0;
            for(k=0; k<c1; k++)
                product[i][j]+=m1[i][k]*m2[k][j];
        }
    }
    return product;
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
