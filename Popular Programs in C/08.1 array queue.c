#include <stdio.h>
#define SIZE 20

int delete (int *, int *, int *);
int insert(int *, int *, int *, int);

int main()
{
    int queue[SIZE] = {0}, front = -1, rear = -1, element, result;
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
        result = insert(queue, &front, &rear, element);
        if (result)
            printf("%d inserted in the linear queue\n", element);
        else
            printf("Insertion failed due to linear queue overflow\n");
        goto loop;
    case 'b':
        result = delete (queue, &front, &rear);
        if (result == NULL)
            printf("Insertion failed due to linear queue underflow\n");
        else
            printf("%d deleted from the linear queue\n", result);
    default:
        goto loop;
    }
    return 0;
}

int delete (int *queue, int *front, int *rear)
{
    if (*front == -1)
        return NULL;
    int element = queue[*front];
    if (*front == *rear && *front != -1)
    {
        *front = -1;
        *rear = -1;
    }
    else
        *front += 1;
    return element;
}

int insert(int *queue, int *front, int *rear, int element)
{
    if (*rear >= SIZE - 1)
        return 0;
    if (*front == -1)
    {
        *front = 0;
        *rear = 0;
    }
    else
        *rear += 1;
    queue[*rear] = element;
    return 1;
}