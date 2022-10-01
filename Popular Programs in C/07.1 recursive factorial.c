// Find the factorial of a number using recursion

#include <stdio.h>
int factorial(int);

int main()
{
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    printf("%d! = %d", num, factorial(num));
    return (0);
}

int factorial(int num)
{
    if (num == 1)
        return;
    return num * factorial(num - 1);
}

/*
------
OUTPUT
------
Enter number: 5
5! = 120
*/