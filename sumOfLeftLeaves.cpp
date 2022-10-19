#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
};

typedef struct Node node;

int n = 10;



node *construct_tree(int a[10], node *root, int i)
{
    if (i >= n)
        return 0;
    root = (node *)malloc(sizeof(node));
    root->data = a[i];
    root->left = construct_tree(a, root, 2 * i + 1);
    root->right = construct_tree(a, root, 2 * i + 2);
    return root;
}

int sumOfLeftLeaves(node *root, int flag = 1)
{
    if (root == 0)
        return 0;
    if (root->left == 0 && root->right == 0 && flag == 0)
    {
        return root->data;
    }

    return sumOfLeftLeaves(root->left, 0) + sumOfLeftLeaves(root->right, 1);
}

int main()
{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *root = construct_tree(a, root, 0);
    int s = sumOfLeftLeaves(root);
    printf("the height of the tree is %d", s);
    return 0;
}