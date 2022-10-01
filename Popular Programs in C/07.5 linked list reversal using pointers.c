// Reverse a linked list without using stack by manipulation of pointers

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

node *create(void);
void reverse(node **);
void display(node *, char *);

void reverse2(node **head)
{
    node *prev = NULL;
    node *current = *head;
    node *next = NULL;
    while (current != NULL)
    {
        // Store next
        next = current->link;

        // Reverse current node's pointer
        current->link = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}

int main()
{
    node *llHead = create();
    display(llHead, "Original");
    reverse2(&llHead);
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

void reverse(node **llHead)
{
    node *current = *llHead;
    node *link;
    while (current->link != NULL)
    {
        link = current->link;
        current->link = link->link;
        link->link = (*llHead);
        *llHead = link;
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