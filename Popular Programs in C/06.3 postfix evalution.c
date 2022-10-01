#include <stdio.h>
int stack[100];
int top = -1;

int pop();
void push(int x);

void main()
{
    char exp[100];
    char *e;
    int n1, n2, n3, num;
    printf("Enter the expression: ");
    scanf("%s", exp);
    e = exp;
    while (*e != '\0')
    {
        if (isdigit(*e))
        {
            num = *e - '0';
            push(num);
        }
        else
        {
            n1 = pop();
            n2 = pop();
            switch (*e)
            {
            case '+':
                n3 = n1 + n2;
                break;
            case '-':
                n3 = n2 - n1;
                break;
            case '*':
                n3 = n1 * n2;
                break;
            case '/':
                n3 = n2 / n1;
                break;
            }
            push(n3);
        }
        e++;
    }
    printf("Result: %d", pop());
}

void push(int x)
{
    stack[++top] = x;
}

int pop()
{
    return stack[top--];
}