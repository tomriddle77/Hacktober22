/*
Create a circular linked list, insert 10 elements and perform the following operations:

a. Insert at beginning
b. Insert at end
c. Insert at middle
d. Delete at beginning
e. Delete at end
f. Delete at middle
g. Display
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

int length(node *);
void display(node *);
void create(node **);
int delete (node **, int);
int insert(node **, int, int);

int main()
{
    node *first;
    create(&first);
    char choice;
    int value, index;
loop:
    printf("\na: Insert at beginning\nb: Insert at end\nc: Insert at middle\nd: Delete at beginning\ne: Delete at end\nf: Delete at middle\ng: Display\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter value to insert at beginning: ");
        scanf("%d", &value);
        insert(&first, value, 0);
        printf("%d inserted at the beginning\n", value);
        goto loop;
    case 'b':
        printf("Enter value to insert at end: ");
        scanf("%d", &value);
        insert(&first, value, length(first));
        printf("%d inserted at the end\n", value);
        goto loop;
    case 'c':
        printf("Enter value to insert and index: ");
        scanf("%d %d", &value, &index);
        if (insert(&first, value, index))
            printf("%d inserted at index %d\n", value, index);
        else
            printf("Index out of bound\n");
        goto loop;
    case 'd':
        value = delete (&first, 0);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the first position deleted\n", value);
        goto loop;
    case 'e':
        value = delete (&first, length(first) - 1);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the last position deleted\n", value);
        goto loop;
    case 'f':
        printf("Enter index of element to delete: ");
        scanf("%d", &index);
        value = delete (&first, index);
        if (value == -99999)
            printf("Empty linked list\n");
        else if (value == -99998)
            printf("Index out of bound\n");
        else
            printf("%d at index %d deleted\n", value, index);
        goto loop;
    case 'g':
        display(first);
        goto loop;
    default:
        printf("Invalid choice\n");
        goto loop;
    }
    return 0;
}

int length(node *first)
{
    int count = 0;
    node *ptr = first->link;
    while (ptr->info != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    return count;
}

int insert(node **first, int value, int index)
{
    int curIndex = 0, lastIndex = length(*first);
    node *new = (node *)malloc(sizeof(node)), *ptr = (*first)->link, *prev = *first;
    new->info = value;
    do
    {
        if (index == curIndex)
        {
            prev->link = new;
            new->link = ptr;
            return 1;
        }
        prev = ptr;
        ptr = ptr->link;
        curIndex++;
    } while (ptr->info != NULL || index == lastIndex);
    return 0;
}

int delete (node **first, int index)
{
    int curIndex = 0, deletedVal;
    node *ptr = (*first)->link, *prev = *first;
    if (ptr == *first)
        return -99999;
    while (ptr->info != NULL)
    {
        if (index == curIndex)
        {
            deletedVal = ptr->info;
            prev->link = ptr->link;
            return deletedVal;
        }
        prev = ptr;
        ptr = ptr->link;
        curIndex++;
    }
    return -99998;
}

void display(node *first)
{
    if (first->link == first)
    {
        printf("Empty circular linked list\n");
        return;
    }
    printf("Circular linked list: +-- ");
    node *ptr = first->link;
    while (1)
    {
        printf("%d", ptr->info);
        ptr = ptr->link;
        if (ptr->info == NULL)
            break;
        printf(" -> ");
    }
    printf(" --+\n");
}

void create(node **first)
{
    int num;
    printf("Enter elements (-999 to stop): ");
    node *new = (node *)malloc(sizeof(node));
    new->info = NULL;
    new->link = new;
    *first = new;
    while (1)
    {
        scanf("%d", &num);
        if (num == -999)
            break;
        insert(first, num, length(*first));
    }
}