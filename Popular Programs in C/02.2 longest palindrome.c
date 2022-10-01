// Find the longest palindrome in an array

#include <stdio.h>
#include <stdlib.h>

int *input(int *size);
int isPalindrome(int *arr, int s, int e);
void longestPalindrome(int *arr,int size);

int main()
{
    int s,*a=input(&s);
    longestPalindrome(a,s);
    return 0;
}

int *input(int *size)
{
    printf("Input array size: ");
    scanf("%d",size);
    int *array=(int*)malloc(sizeof(int)*(*size)), i;
    printf("Enter array elements: ");
    for(i=0; i<*size; i++)
    {
        scanf("%d",&array[i]);
    }
    return array;
}

int isPalindrome(int *arr, int s, int e)
{
    int i;
    for(i=0; i<(s+e+1)/2; i++)
    {
        if(arr[s+i]!=arr[e-i]) return 0;
    }
    return 1;
}

void longestPalindrome(int *arr,int size)
{
    int i,j,k;
    for(i=size; i>=1; i--)
    {
        for(j=0; j+i-1<size; j+=1)
        {
            if(isPalindrome(arr,j,j+i-1))
            {
                printf("Longest palindrome: ");
                for(k=j;k<=j+i-1; k++) printf("%d ",arr[k]);
                return;
            }
        }
    }
}
