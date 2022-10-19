#include <stdio.h>
#include <stdlib.h>


struct Node
{
    struct Node*left;
    struct Node*right;
    int freq;
    int data;
};




typedef struct Node node;

int n = 10;

void preorder(node *root)
{
    if (root == 0)
        return;
    printf("%d ", root->data);

    preorder(root->left);

    preorder(root->right);
}

node* construct_tree(int a[10],node*root,int i)
{
     if(i>=n)
         return 0;
     root = (node *)malloc(sizeof(node));
     root->data = a[i];
     root->left = construct_tree(a,root,2*i+1);
     root->right = construct_tree(a, root, 2 * i + 2);
     return root;
}

int main()
{

    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *root = construct_tree(a, root, 0);
    preorder(root);
    return 0;
}