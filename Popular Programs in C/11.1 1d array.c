#include <stdio.h>
#include <stdlib.h>

int *create(int *size);
void display(int array[], int size);
int search(int array[], int size, int element);
void sort(int array[], int size);
int *insert(int array[], int *size, int element, int position);
int delete (int array[], int *size, int index);

void main()
{
    int size, *array = create(&size);
    int choice, toSearch, toInsert, index;

loop:
    printf("\n1: Search\n2: Sort\n3: Insert\n4: Delete\n5: Display\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Enter element to search: ");
        scanf("%d", &toSearch);
        index = search(array, size, toSearch);
        if (index != -1)
            printf("%d found at index %d\n", toSearch, index);
        else
            printf("%d not found in the array\n", toSearch);
        goto loop;

    case 2:
        sort(array, size);
        printf("Array sorted\n");
        goto loop;

    case 3:
        printf("Enter the element to insert and its index: ");
        scanf("%d %d", &toInsert, &index);
        array = insert(array, &size, toInsert, index);
        printf("%d inserted at index %d\n", toInsert, index);
        goto loop;

    case 4:
        printf("Enter element index to delete: ");
        scanf("%d", &index);
        if (delete (array, &size, index))
            printf("Element deleted\n");
        else
            printf("Index doesn't exist\n");
        goto loop;

    case 5:
        display(array, size);
        goto loop;

    default:
        goto loop;
    }
}

int *create(int *size)
{
    printf("Total elements: ");
    scanf("%d", size);
    int *array = (int *)malloc((*size) * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < *size; i++)
        scanf("%d", &array[i]);
    return array;
}

void display(int array[], int size)
{
    printf("Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", array[i]);
        if (i != size - 1)
            printf(", ");
    }
    printf("\n");
}

int search(int array[], int size, int element)
{
    for (int i = 0; i < size; i++)
        if (array[i] == element)
            return i;
    return -1;
}

void sort(int array[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < size; j++)
        {
            if (array[j - 1] > array[j])
            {
                temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

int *insert(int array[], int *size, int element, int position)
{
    int oldSize = *size;
    if (position <= *size)
        *size += 1;
    else
        *size = position + 1;
    int *newArray = (int *)malloc((*size) * sizeof(int));
    for (int i = 0; i < *size; i++)
    {
        if (i < oldSize)
            newArray[i] = array[i];
        else
            newArray[i] = 0;
    }
    free(array);
    for (int i = *size - 1; i >= position; i--)
    {
        if (i != *size - 1)
            newArray[i + 1] = newArray[i];
        if (i == position)
            newArray[i] = element;
    }
    return newArray;
}

int delete (int array[], int *size, int index)
{
    if (index >= *size)
        return 0;
    for (int i = index; i < *size - 1; i++)
        array[i] = array[i + 1];
    (*size)--;
    return 1;
}