// WAP to implement double ended queue using array

#include <stdio.h>
#define MAX 5

int deleteBeg(int *, int *, int *);
int deleteEnd(int *, int *, int *);
int insertEnd(int *, int *, int *, int);
int insertBeg(int *, int *, int *, int);

int main()
{
    int deque[MAX], l = -1, r = -1, element;
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
        if (insertBeg(deque, &l, &r, element))
            printf("%d inserted at beginning\n", element);
        else
            printf("Insertion failed due to deque overflow\n");
        goto loop;
    case 'b':
        printf("Enter element to insert: ");
        scanf("%d", &element);
        if (insertEnd(deque, &l, &r, element))
            printf("%d inserted at end\n", element);
        else
            printf("Insertion failed due to deque overflow\n");
        goto loop;
    case 'c':
        element = deleteBeg(deque, &l, &r);
        if (element != NULL)
            printf("%d deleted from beginning\n", element);
        else
            printf("Deletion failed due to deque underflow\n");
        goto loop;
    case 'd':
        element = deleteEnd(deque, &l, &r);
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

int insertEnd(int *deque, int *l, int *r, int element)
{
    if ((*l == 0 && *r == MAX - 1) || (*l == *r + 1))
        return 0;
    if (*l == -1)
    {
        *l = 0;
        *r = 0;
    }
    else if (*r == MAX - 1)
        *r = 0;
    else
        *r = *r + 1;
    deque[*r] = element;
}

int insertBeg(int *deque, int *l, int *r, int element)
{
    if ((*l == 0 && *r == MAX - 1) || (*l == *r + 1))
        return 0;
    if (*l == -1)
    {
        *l = 0;
        *r = 0;
    }
    else if (*l == 0)
        *l = MAX - 1;
    else
        *l = *l - 1;
    deque[*l] = element;
    return 1;
}

int deleteBeg(int *deque, int *l, int *r)
{
    int deleted;
    if (*l == -1)
        return NULL;
    deleted = deque[*l];
    if (*l == *r)
    {
        *l = -1;
        *r = -1;
    }
    else if (*l == MAX - 1)
        *l = 0;
    else
        *l = *l + 1;
    return deleted;
}

int deleteEnd(int *deque, int *l, int *r)
{
    int deleted;
    if (*l == -1)
        return NULL;
    deleted = deque[*r];
    if (*l == *r)
    {
        *l = -1;
        *r = -1;
    }
    else if (*r == 0)
        *r = MAX - 1;
    else
        *r = *r - 1;
    return deleted;
}