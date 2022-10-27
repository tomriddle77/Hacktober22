// Bubble Sort
#include <stdio.h>

int main()
{
    int size;
    printf("Enter the size of the array: ");
    scanf("%d",&size);
    int arr[size];
    input(arr,size);
    sortArray(arr,size);
    display(arr,size);
}

void input(int b[],int N)
{
    printf("Enter values of %d array: ",N);
    for(int i = 0;i < N; i++)
    {
        scanf("%d",&b[i]);
    }
}

void display(int b[],int N)
{
    printf("Enter values of array are: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
}

void sortArray(int b[],int N)
{
    int temp;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N-i; j++)
        {
            if(b[j] > b[j+1])
            {
                temp = b[j+1];
                b[j+1] = b[j];
                b[j] = temp;
            }
        }
    }
}
