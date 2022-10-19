#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    int freq;
    int data;
};

typedef struct Node node;

int n = 10;

int max(int a, int b)
{
    return a > b ? a : b;
}

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
int maxx=0;
int diameter(node *root)
{
    if (root == 0)
    {
        return 0;
    }

    int lh = diameter(root->left);
    int rh = diameter(root->right);
    maxx = max(maxx, lh + rh);
    return 1 + max(lh, rh);
}

int main()
{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *root = construct_tree(a, root, 0);
    int d = diameter(root);
    printf("the diameter of the tree is %d",maxx );
    return 0;
}