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
        printf("%d inserted in the circular queue\n", element);
        goto loop;
    case 'b':
        element = delete (&front, &rear);
        if (element == NULL)
            printf("Insertion failed due to circular queue underflow\n");
        else
            printf("%d deleted from the circular queue\n", element);
        goto loop;
    default:
        goto loop;
    }
    return 0;
}

int delete (node **front, node **rear)
{
    if (*front == NULL)
        return NULL;

    int value;
    if (*front == *rear)
    {
        value = (*front)->info;
        free(*front);
        *front = NULL;
        *rear = NULL;
    }
    else
    {
        node *temp = *front;
        value = temp->info;
        *front = (*front)->link;
        (*rear)->link = *front;
        free(temp);
    }
    return value;
}

void insert(node **front, node **rear, int element)
{
    node *new = (node *)malloc(sizeof(node));
    new->info = element;
    if (*front == NULL)
        *front = new;
    else
        (*rear)->link = new;

    *rear = new;
    (*rear)->link = *front;
}