/*
Create a linked list with some elements and perform the following operations:

a. Insert element at the beginning
b. Insert element at the end
c. Insert element in the middle
d. Delete element at the beginning
e. Delete element at the end
f. Delete element in the middle
g. Display all elements
h. Search an element by value
i: Sort the linked list
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

node *create(void);
void insertAtBeginning(node **, int);
void insertAtEnd(node **, int);
int insertAtMiddle(node **, int, int);
int deleteFirst(node **);
int deleteLast(node **);
int deleteMiddle(node **, int);
void display(node *);
int searchElement(node *, int);
void swap(node *, node *);
void sort(node *);

int main()
{
    node *first = create();
    char choice;
    int value, index;
loop:
    printf("\na: Insert element at the beginning\nb: Insert element at the end\nc: Insert element in the middle\nd: Delete element at the beginning\ne: Delete element at the end\nf: Delete element in the middle\ng: Display all elements\nh: Search an element by value\ni: Sort the linked list\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter value to insert at beginning: ");
        scanf("%d", &value);
        insertAtBeginning(&first, value);
        printf("%d inserted at the beginning\n", value);
        goto loop;
    case 'b':
        printf("Enter value to insert at end: ");
        scanf("%d", &value);
        insertAtEnd(&first, value);
        printf("%d inserted at the end\n", value);
        goto loop;
    case 'c':
        printf("Enter value to insert and index: ");
        scanf("%d %d", &value, &index);
        if (insertAtMiddle(&first, value, index))
            printf("%d inserted at index %d\n", value, index);
        else
            printf("Index out of bound\n");
        goto loop;
    case 'd':
        value = deleteFirst(&first);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the first position deleted\n", value);
        goto loop;
    case 'e':
        value = deleteLast(&first);
        if (value == -99999)
            printf("Empty linked list\n");
        else
            printf("%d at the last position deleted\n", value);
        goto loop;
    case 'f':
        printf("Enter index of element of delete: ");
        scanf("%d", &index);
        value = deleteMiddle(&first, index);
        if (value == -99999)
            printf("Empty linked list\n");
        else if (value == -99998)
            printf("Index out of bound\n");
        else
            printf("%d at the last position deleted\n", value);
        goto loop;
    case 'g':
        display(first);
        goto loop;
    case 'h':
        printf("Enter an element to search: ");
        scanf("%d", &value);
        index = searchElement(first, value);
        if (index == -2)
            printf("Empty linked list\n");
        else if (index == -1)
            printf("Element not found\n");
        else
            printf("%d found at index %d\n", value, index);
        goto loop;
    case 'i':
        sort(first);
        printf("Linked list sorted\n");
        goto loop;
    default:
        printf("Invalid choice\n");
        goto loop;
    }
    return 0;
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

void insertAtBeginning(node **first, int value)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = value;
    new->link = *first;
    *first = new;
}

void insertAtEnd(node **first, int value)
{
    node *new = (node *)malloc(sizeof(node)), *llptr = *first;
    new->info = value;
    new->link = NULL;
    if (*first == NULL)
    {
        *first = new;
        return;
    }
    while (llptr->link != NULL)
        llptr = llptr->link;
    llptr->link = new;
}

int insertAtMiddle(node **first, int value, int index)
{
    int curIndex = 0;
    node *new = (node *)malloc(sizeof(node)), *llptr = *first, *prev;
    new->info = value;
    if (index == 0)
    {
        new->link = *first;
        *first = new;
        return 1;
    }
    while (llptr->link != NULL)
    {
        prev = llptr;
        llptr = llptr->link;
        curIndex++;
        if (index == curIndex)
        {
            prev->link = new;
            new->link = llptr;
            return 1;
        }
    }
    return 0;
}

int deleteFirst(node **first)
{
    if (*first == NULL)
        return -99999;
    int deletedVal = (*first)->info;
    node *toFree = *first;
    *first = (*first)->link;
    free(toFree);
    return deletedVal;
}

int deleteLast(node **first)
{
    if (*first == NULL)
        return -99999;
    node *llptr = *first, *prev = NULL;
    while (llptr->link != NULL)
    {
        prev = llptr;
        llptr = llptr->link;
    }
    int deletedVal = llptr->info;
    free(llptr);
    if (prev == NULL)
        *first = NULL;
    else
        prev->link = NULL;
    return deletedVal;
}

int deleteMiddle(node **first, int index)
{
    int curIndex = 0, deletedVal;
    if (*first == NULL)
        return -99999;
    if (index == 0)
    {
        deletedVal = (*first)->info;
        node *toFree = *first;
        *first = (*first)->link;
        free(toFree);
        return deletedVal;
    }
    node *llptr = *first, *nodeAfterDel;
    while (1)
    {
        if (curIndex == index - 1)
        {
            deletedVal = llptr->link->info;
            node *toFree = llptr->link;
            nodeAfterDel = llptr->link->link;
            llptr->link = nodeAfterDel;
            free(toFree);
            return deletedVal;
        }
        if (llptr->link == NULL)
            return -99998;
        llptr = llptr->link;
        curIndex++;
    }
}

void display(node *first)
{
    if (first == NULL)
    {
        printf("Empty linked list\n");
        return;
    }
    printf("Linked list: ");
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

int searchElement(node *first, int element)
{
    if (first == NULL)
        return -2;
    int index = 0;
    node *llptr = first;
    while (1)
    {
        if (llptr->info == element)
            return index;
        else if (llptr->link == NULL)
            return -1;
        llptr = llptr->link;
        index++;
    }
}

void swap(node *a, node *b)
{
    int temp = a->info;
    a->info = b->info;
    b->info = temp;
}

void sort(node *first)
{
    int swapped;
    node *ptr1, *lptr = NULL;
    if (first == NULL)
        return;
    do
    {
        swapped = 0;
        ptr1 = first;
        while (ptr1->link != lptr)
        {
            if (ptr1->info > ptr1->link->info)
            {
                swap(ptr1, ptr1->link);
                swapped = 1;
            }
            ptr1 = ptr1->link;
        }
        lptr = ptr1;
    } while (swapped);
}