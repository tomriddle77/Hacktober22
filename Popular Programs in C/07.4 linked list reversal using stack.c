// Reverse a linked list using stack

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

int pop(node **);
node *create(void);
void reverse(node **);
void push(node **, int);
void display(node *, char *);

int main()
{
    node *llHead = create();
    display(llHead, "Original");
    reverse(&llHead);
    display(llHead, "Reversed");
    return (0);
}

node *create(void)
{
    int num;
    node *first = (node *)malloc(sizeof(node)), *llptr = first;
    printf("Enter elements (-999 to stop): ");
    scanf("%d", &llptr->info);
    while (1)
    {
        scanf("%d", &num);
        if (num == -999)
        {
            llptr->link = NULL;
            break;
        }
        llptr->link = (node *)malloc(sizeof(node));
        llptr = llptr->link;
        llptr->info = num;
    }
    return first;
}

void display(node *first, char *text)
{
    if (first == NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    printf("%s linked list: ", text);
    node *llptr = first;
    while (1)
    {
        printf("%d", llptr->info);
        if (llptr->link == NULL)
            break;
        else
            llptr = llptr->link;
        printf(" -> ");
    }
    printf("\n");
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

void reverse(node **llHead)
{
    node *stack = NULL, *llPtr = *llHead;
    while (llPtr)
    {
        push(&stack, llPtr->info);
        llPtr = llPtr->link;
    }
    llPtr = *llHead;
    while (llPtr)
    {
        llPtr->info = pop(&stack);
        llPtr = llPtr->link;
    }
}

/*
------
OUTPUT
------
Enter elements (-999 to stop): 1 2 3 4 5 -999
Original linked list: 1 -> 2 -> 3 -> 4 -> 5
Reversed linked list: 5 -> 4 -> 3 -> 2 -> 1
*/