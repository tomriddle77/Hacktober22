#include <stdio.h>
#include <stdlib.h>

typedef struct nodeStruct
{
    int info;
    struct nodeStruct *link;
} node;

int delete (node **, node **);
void insert(node **, node **, int);

int main()
{
    node *front = NULL, *rear = NULL;
    int element;
    char choice;
loop:
    printf("\na: Insert\nb: Delete\n\nEnter your choice: ");
    fflush(stdin);
    scanf("%c", &choice);
    fflush(stdin);
    system("cls");
    switch (choice)
    {
    case 'a':
        printf("Enter element to insert: ");
        scanf("%d", &element);
        insert(&front, &rear, element);
        printf("%d inserted in the linear queue\n", element);
        goto loop;
    case 'b':
        element = delete (&front, &rear);
        if (element == NULL)
            printf("Deletion failed due to linear queue underflow\n");
        else
            printf("%d deleted from the linear queue\n", element);
    default:
        goto loop;
    }
    return 0;
}

int delete (node **front, node **rear)
{
    if (*front == NULL)
        return NULL;
    int element = (*front)->info;
    if (*front == *rear)
    {
        *front = NULL;
        *rear = NULL;
    }
    else
        *front = (*front)->link;
    return element;
}

void insert(node **front, node **rear, int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = element;
    new->link = NULL;
    if (*rear == NULL)
    {
        *front = new;
        *rear = new;
    }
    else
    {
        (*rear)->link = new;
        *rear = new;
    }
}