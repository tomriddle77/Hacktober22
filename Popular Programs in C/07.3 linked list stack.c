// Perform the following operations for linked stack: (a) Push (b) Pop

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

void push(node **, int);
int pop(node **);

int main()
{
    node *stack = NULL;
    int element, result;
    char choice;
loop:
    printf("\na: Push\nb: Pop\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter element to push: ");
        scanf("%d", &element);
        push(&stack, element);
        printf("%d pushed to stack\n", element);
        goto loop;
    case 'b':
        result = pop(&stack);
        if (result == NULL)
            printf("Pop operation failed due to stack underflow\n");
        else
            printf("%d popped from stack\n", result);
        goto loop;
    default:
        goto loop;
    }
    return 0;
}

void push(node **top, int info)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = info;
    new->link = *top;
    *top = new;
}

int pop(node **top)
{
    if (*top == NULL)
        return NULL;
    int popped = (*top)->info;
    node *toFree = *top;
    *top = (*top)->link;
    free(toFree);
    return popped;
}

/*
------
OUTPUT
------
1
------
a: Push
b: Pop

Enter your choice: a

------
2
------
Enter element to push: 1
1 pushed to stack

a: Push
b: Pop

Enter your choice: b

------
3
------
1 popped from stack

a: Push
b: Pop

Enter your choice: b

------
4
------
Pop operation failed due to stack underflow

a: Push
b: Pop

Enter your choice:
*/