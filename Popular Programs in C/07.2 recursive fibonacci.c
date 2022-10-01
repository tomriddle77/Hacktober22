// Display fibonacci series using recursion

#include <stdio.h>
int fibonacci(int);

int main()
{
    int terms;
    printf("Enter total fibonacci series terms to display: ");
    scanf("%d", &terms);
    printf("Fibonacci series: ");
    for (int term = 0; term < terms; term++)
        printf("%d ", fibonacci(term));
    return (0);
}

int fibonacci(int term)
{
    if (term == 0)
        return 0;
    else if (term == 1)
        return 1;
    return (fibonacci(term - 1) + fibonacci(term - 2));
}

/*
------
OUTPUT
------
Enter total fibonacci series terms to display: 6
Fibonacci series: 0 1 1 2 3 5
*/