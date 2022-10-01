// WAP to implement double ended queue using linkedlist

#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int data;
    struct nodeStruct *previous, *next;
} node;

node *createNode(int);
void insertBeg(node **, int);
void insertEnd(node **, int);
int deleteBeg(node **, node **);
int deleteEnd(node **, node **);
void initialize(node **, node **);

int main()
{
    node *head = NULL, *tail = NULL;
    initialize(&head, &tail);
    int element;
    char choice;
loop:
    printf("\na: Insert at beginning\nb: Insert at end\nc: Delete from beginning\nd: Delete from end\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter element to insert: ");
        scanf("%d", &element);
        insertBeg(&head, element);
        printf("%d inserted at beginning\n", element);
        goto loop;
    case 'b':
        printf("Enter element to insert: ");
        scanf("%d", &element);
        insertEnd(&tail, element);
        printf("%d inserted at end\n", element);
        goto loop;
    case 'c':
        element = deleteBeg(&head, &tail);
        if (element != NULL)
            printf("%d deleted from beginning\n", element);
        else
            printf("Deletion failed due to deque underflow\n");
        goto loop;
    case 'd':
        element = deleteEnd(&head, &tail);
        if (element != NULL)
            printf("%d deleted from end\n", element);
        else
            printf("Deletion failed due to deque underflow\n");
        goto loop;
    default:
        goto loop;
    }
    return 0;
}

node *createNode(int data)
{
    node *nnode = (node *)malloc(sizeof(node));
    nnode->data = data;
    nnode->next = nnode->previous = NULL;
    return nnode;
}

void initialize(node **head, node **tail)
{
    *head = createNode(0);
    *tail = createNode(0);
    (*head)->next = *tail;
    (*tail)->previous = *head;
}

void insertBeg(node **head, int data)
{
    node *nnode, *temp;
    nnode = createNode(data);
    temp = (*head)->next;
    (*head)->next = nnode;
    nnode->previous = *head;
    nnode->next = temp;
    temp->previous = nnode;
}

void insertEnd(node **tail, int data)
{
    node *nnode, *temp;
    nnode = createNode(data);
    temp = (*tail)->previous;
    (*tail)->previous = nnode;
    nnode->next = *tail;
    nnode->previous = temp;
    temp->next = nnode;
}

int deleteBeg(node **head, node **tail)
{
    node *temp;
    int deleted;
    if ((*head)->next == *tail)
        return NULL;
    else
    {
        temp = (*head)->next;
        (*head)->next = temp->next;
        temp->next->previous = *head;
        deleted = temp->data;
        free(temp);
    }
    return deleted;
}

int deleteEnd(node **head, node **tail)
{
    node *temp;
    int deleted;
    if ((*tail)->previous == *head)
        return NULL;
    else
    {
        temp = (*tail)->previous;
        (*tail)->previous = temp->previous;
        temp->previous->next = *tail;
        deleted = temp->data;
        free(temp);
    }
    return deleted;
}