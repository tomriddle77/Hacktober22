/*
Create a double linked list, insert 10 elements and perform the following operations:

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
    struct nodeStruct *next;
    struct nodeStruct *prev;
} node;

int length(node *);
void display(node *);
void create(node **, node **);
int delete (node **, node **, int);
int insert(node **, node **, int, int);

int main()
{
    node *first = NULL, *last = NULL;
    create(&first, &last);
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
        insert(&first, &last, value, 0);
        printf("%d inserted at the beginning\n", value);
        goto loop;
    case 'b':
        printf("Enter value to insert at end: ");
        scanf("%d", &value);
        insert(&first, &last, value, length(first));
        printf("%d inserted at the end\n", value);
        goto loop;
    case 'c':
        printf("Enter value to insert and index: ");
        scanf("%d %d", &value, &index);
        if (insert(&first, &last, value, index))
            printf("%d inserted at index %d\n", value, index);
        else
            printf("Index out of bound\n");
        goto loop;
    case 'd':
        value = delete (&first, &last, 0);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the first position deleted\n", value);
        goto loop;
    case 'e':
        value = delete (&first, &last, length(first) - 1);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the last position deleted\n", value);
        goto loop;
    case 'f':
        printf("Enter index of element to delete: ");
        scanf("%d", &index);
        value = delete (&first, &last, index);
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
    node *ptr = first;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

void display(node *first)
{
    if (first == NULL)
    {
        printf("Empty double linked list\n");
        return;
    }
    printf("Double linked list: ");
    node *ptr = first;
    while (ptr != NULL)
    {
        printf("%d", ptr->info);
        ptr = ptr->next;
        if (ptr != NULL)
            printf(" <-> ");
    }
    printf("\n");
}

int insert(node **first, node **last, int value, int index)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = value;
    if (*first == NULL && index == 0)
    {
        new->next = NULL;
        new->prev = NULL;
        *first = new;
        *last = new;
        return 1;
    }
    else if (index == 0)
    {
        new->next = *first;
        new->prev = NULL;
        *first = new;
        return 1;
    }
    int curIndex = 1, lastIndex = length(*first);
    node *ptr = (*first)->next, *prev = *first;
    do
    {
        if (index == curIndex)
        {
            new->next = ptr;
            new->prev = prev;
            prev->next = new;
            if (index != lastIndex)
                ptr->prev = new;
            else
                *last = new;
            return 1;
        }
        prev = ptr;
        ptr = ptr->next;
        curIndex++;
    } while (ptr != NULL || index == lastIndex);
    return 0;
}

int delete (node **first, node **last, int index)
{
    int deletedVal, lastIndex = length(*first) - 1;
    if (*first == NULL)
        return -99999;
    if (index == 0)
    {
        deletedVal = (*first)->info;
        *first = (*first)->next;
        if (index == lastIndex)
            *last = NULL;
        return deletedVal;
    }
    int curIndex = 1;
    node *ptr = (*first)->next, *prev = *first;
    do
    {
        if (index == curIndex)
        {
            deletedVal = ptr->info;
            if (index != lastIndex)
                ptr->next->prev = prev;
            else
                *last = NULL;
            prev->next = ptr->next;
            return deletedVal;
        }
        prev = ptr;
        ptr = ptr->next;
        curIndex++;
    } while (ptr != NULL || index == lastIndex);
    return -99998;
}

void create(node **first, node **last)
{
    int num;
    printf("Enter elements (-999 to stop): ");
    while (1)
    {
        scanf("%d", &num);
        if (num == -999)
            break;
        insert(first, last, num, length(*first));
    }
}