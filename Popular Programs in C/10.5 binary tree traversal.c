// WAP to traverse a binary tree

#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int info;
    struct tree_node *left;
    struct tree_node *right;
} node;

void create(node **);
node *insert(node *, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);

void main()
{
    node *root = NULL;
    create(&root);
    printf("\nPreorder : ");
    preorder(root);
    printf("\nInorder  : ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
}

void create(node **root)
{
    int s, ele;
    printf("Enter total elements: ");
    scanf("%d", &s);
    printf("Enter bst elements: ");
    for (int i = 0; i < s; i++)
    {
        scanf("%d", &ele);
        *root = insert(*root, ele);
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
    }
    else if (element < root->info)
        root->left = insert(root->left, element);
    else if (element >= root->info)
        root->right = insert(root->right, element);
    return root;
}

void preorder(node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->info);
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->info);
    inorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->info);
}

/*
Enter total elements: 5
Enter bst elements: 4 1 5 2 3

Preorder : 4 1 2 3 5
Inorder  : 1 2 3 4 5
Postorder: 3 2 1 5 4
*/