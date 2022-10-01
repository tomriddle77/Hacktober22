#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int info;
    struct tree_node *left;
    struct tree_node *right;
} node;

node *insert(node *root, int element);
void displayPreorder(node *root);
void displayInorder(node *root);
void displayPostorder(node *root);
void displayDiagram(node *root, int level);
void search(node *root, int element);
node *delete (node *root, int element);

void main()
{
    node *root = NULL;
    int choice, element;
loop:
    printf("\n1: Insert\n2: Display pre-order\n3: Display in-order\n4: Display post-order\n5: Display diagram\n6: Search\n7: Delete\n\nEnter your choice: ");
    scanf("%d", &choice);
    system("cls");
    switch (choice)
    {
    case 1:
        printf("Enter element: ");
        scanf("%d", &element);
        root = insert(root, element);
        goto loop;
    case 2:
        displayPreorder(root);
        goto loop;
    case 3:
        displayInorder(root);
        goto loop;
    case 4:
        displayPostorder(root);
        goto loop;
    case 5:
        displayDiagram(root, 0);
        goto loop;
    case 6:
        printf("Enter element to search: ");
        scanf("%d", &element);
        search(root, element);
        goto loop;
    case 7:
        printf("Enter element to delete: ");
        scanf("%d", &element);
        root = delete (root, element);
        printf("Deleted\n");
        goto loop;
    default:
        goto loop;
    }
}

node *insert(node *root, int element)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->info = element;
        root->left = NULL;
        root->right = NULL;
        printf("Element inserted\n");
    }
    else if (element < root->info)
        root->left = insert(root->left, element);
    else if (element > root->info)
        root->right = insert(root->right, element);
    else if (element == root->info)
        printf("Duplicate entry\n");
    return root;
}

void displayPreorder(node *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        displayPreorder(root->left);
        displayPreorder(root->right);
    }
}

void displayDiagram(node *root, int level)
{
    if (root != NULL)
    {
        for (int i = 0; i < level; i++)
            printf(i == level - 1 ? "|-" : "  ");
        printf("%d\n", root->info);
        displayDiagram(root->left, level + 1);
        displayDiagram(root->right, level + 1);
    }
}

void displayInorder(node *root)
{
    if (root != NULL)
    {
        displayInorder(root->left);
        printf("%d\n", root->info);
        displayInorder(root->right);
    }
}

void displayPostorder(node *root)
{
    if (root != NULL)
    {
        displayPostorder(root->left);
        displayPostorder(root->right);
        printf("%d\n", root->info);
    }
}

void search(node *root, int element)
{
    if (root == NULL)
        printf("Element not present in the BST\n");
    else if (element == root->info)
        printf("Element present in the BST\n");
    else if (element < root->info)
        search(root->left, element);
    else if (element > root->info)
        search(root->right, element);
}

node *delete (node *root, int element)
{
    node *ptr;
    if (root == NULL)
        return root;
    else if (element < root->info)
        root->left = delete (root->left, element);
    else if (element > root->info)
        root->right = delete (root->right, element);
    else
    {
        if (root->left == NULL)
        {
            ptr = root->right;
            free(root);
            return ptr;
        }
        else if (root->right == NULL)
        {
            ptr = root->left;
            free(root);
            return ptr;
        }
        else
        {
            ptr = root->right;
            while (ptr && ptr->left != NULL)
                ptr = ptr->left;
            root->info = ptr->info;
            root->right = delete (root->right, ptr->info);
        }
    }
    return root;
}